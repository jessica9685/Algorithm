// 17837_새로운_게임2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 13

typedef struct Horse {
	int y, x; // 위치
	int d; // 방향
};

int n, k;
int dy[5] = { 0, 0, 0, -1, 1 }; // right, left, up, down
int dx[5] = { 0, 1, -1, 0, 0 };
int board[MAX][MAX]; // 0: white, 1: red, 2: blue
vector<int> state[MAX][MAX]; // 각 말의 위치 현황
vector<Horse> horse; // 각 말의 위치, 방향

// 뱡향을 반대로 바꿈
int reverse_dir(int d) {
	if (d == 1) d = 2;
	else if (d == 2) d = 1;
	else if (d == 3) d = 4;
	else if (d == 4) d = 3;

	return d;
}

// 몇 개의 말을 옮겨야 하는지
int moving_idx (int num, int y, int x) {
	int idx = 0;
	for (int i = 0; i < state[y][x].size(); i++) {
		if (state[y][x][i] == num) {
			idx = i;
			break;
		}
	}
	return idx;
}

vector<int> moving_horse(int num, int y, int x) {
	vector<int> res; // 옮기는 말 목록
	int idx = moving_idx(num, y, x);
	for (int i = idx; i < state[y][x].size(); i++) res.push_back(state[y][x][i]);
	// 원래 있던 곳의 말 지우기
	state[y][x].erase(state[y][x].begin() + idx, state[y][x].end());
	return res;
}

// 각 말 이동
// num: 말 번호, nState: 다음 칸 상태
void move(int y, int x, int ny, int nx, int num, int nState) {
	// 흰색 또는 빨간색인 경우
	if (nState != 2) {
		vector<int> moving = moving_horse(num, y, x); // 이동하는 말 벡터
		// 이동하려는 칸이 빨간색이면 순서 반대로
		if (board[ny][nx] == 1) reverse(moving.begin(), moving.end());
		// 이동
		for (auto h : moving) {
			state[ny][nx].push_back(h);
			horse[h].y = ny;
			horse[h].x = nx;
 		}
	}
	// 파란색이거나 범위 밖인 경우
	else {
		// 이동방향 반대로
		int d = reverse_dir(horse[num].d); 
		horse[num].d = d;
		int nny = y + dy[d];
		int nnx = x + dx[d];

		// 이동한 칸이 범위 내이고
		if (nny > 0 && nnx > 0 && nny <= n && nnx <= n) {
			// 파란색이 아니면
			if (board[nny][nnx] != 2) move(y, x, nny, nnx, num, board[nny][nnx]);
		}
	}
}

bool isDone() {
	bool result = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			if (state[i][j].size() >= 4) {
				result = true;
				break;
			}
		}
	}
	return result;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	horse.resize(k + 1);
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &horse[i].y, &horse[i].x, &horse[i].d);
		state[horse[i].y][horse[i].x].push_back(i);
	}

	int turn = 1;
	bool finish = false;
	while (true) {
		if (turn > 1000) {
			turn = -1;
			break;
		}

		for (int h = 1; h <= k; h++) {
			int y = horse[h].y, x = horse[h].x;
			int d = horse[h].d;

			int ny = y + dy[d];
			int nx = x + dx[d];		

			// 범위 밖인 경우 파란색일 때와 똑같이
			if (ny < 1 || nx < 1 || ny > n || nx > n) move(y, x, ny, nx, h, 2);
			else move(y, x, ny, nx, h, board[ny][nx]);

			// 게임 종료
			if (isDone()) {
				finish = true;
				break;
			}
		}

		if (finish) break;
		turn++;
	}
	printf("%d\n", turn);
	return 0;
}
