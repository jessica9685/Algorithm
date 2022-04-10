// 23288_주사위_굴리기2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 21

// 보이는 세 면
typedef struct Dice {
	int up;
	int front;
	int side;
};

int n, m, k;
int board[MAX][MAX];
int dy[4] = { 0, 1, 0, -1 }; // 동, 남, 서, 북
int dx[4] = { 1, 0, -1, 0 };
int dir; // 이동방향
Dice dice; // 주사위

// 점수 계산
int scoring(int sy, int sx) {
	bool visited[MAX][MAX] = { false, };
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;

	int cnt = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
			if (visited[ny][nx]) continue;
			if (board[y][x] == board[ny][nx]) {
				cnt++;
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

	int result = cnt * board[sy][sx];
	return result;
}

void move_dice(int d) {
	Dice copy = dice;
	if (d == 0) { // 동
		dice.up = 7 - copy.side;
		dice.side = copy.up;
	}
	else if (d == 1) { // 남
		dice.up = 7 - copy.front;
		dice.front = copy.up;
	}
	else if (d == 2) { // 서
		dice.up = copy.side;
		dice.side = 7 - copy.up;
	}
	else { // 북
		dice.up = copy.front;
		dice.front = 7 - copy.up;
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	// 초기화
	int y = 1;
	int x = 1;
	dir = 0; // east
	int score = 0; // 점수
	dice = { 1, 5, 3 }; // 주사위

	while (k--) {
		/* 1. 주사위 한 칸 이동 */
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		// 범위를 벗어나면 이동방향을 반대로
		if (ny < 1 || nx < 1 || ny > n || nx > m) {
			dir = (dir + 2) % 4;
			ny = y + dy[dir];
			nx = x + dx[dir];
		}
		move_dice(dir);

		/* 2. 점수 획득 */
		score += scoring(ny, nx);

		/* 3. 이동방향 결정 */
		int floor = 7 - dice.up;
		if (floor > board[ny][nx]) { // 시계뱡향
			dir = (dir + 1) % 4;
		}
		else if (floor < board[ny][nx]) { // 반시계방향
			if (dir == 0) dir = 3;
			else dir--;
		}
		y = ny;
		x = nx;
	}

	printf("%d\n", score);
	return 0;
}
