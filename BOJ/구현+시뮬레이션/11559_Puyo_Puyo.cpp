// 11559_Puyo_Puyo.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char board[12][6];
char copied[12][6];
bool visited[12][6];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

typedef struct puyo {
	int y;
	int x;
	char color;
};

// 뿌요 1개를 아래로 떨어뜨리는 함수
void move_down(int y, int x, char color) {
	int ny = y;

	while (true) {
		ny++;
		if (ny >= 12 
			|| (ny < 12 && board[ny][x] != '.')) {
			ny--;
			break;
		}
	}
	
	if(ny != y) board[y][x] = '.';
	board[ny][x] = color;
}

void bomb() {
	stack<puyo> s;
	// 터트리기
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			// X로 표시된 부분을 빈칸으로 바꾸고
			if (board[i][j] == 'X') {
				board[i][j] = '.';
				continue;
			}
			// 남은 뿌요는 스택에 push
			if (board[i][j] != '.') {
				s.push({ i, j, board[i][j] });
			}
		}
	}

	// 남은 뿌요들을 아래로 떨어뜨리기
	// 아래줄부터 시작
	while (!s.empty()) {
		int y = s.top().y;
		int x = s.top().x;
		int color = s.top().color;
		s.pop();

		move_down(y, x, color);
	}
}

bool pop(pair<int, int> start) {
	memcpy(copied, board, sizeof(board));
	memset(visited, false, sizeof(visited));

	int cnt = 1;
	char color = board[start.first][start.second];
	queue<pair<int, int>> q;
	visited[start.first][start.second] = true;
	q.push(start);
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || ny >= 12 || nx >= 6) continue;
			if (visited[ny][nx]) continue;
			if (board[ny][nx] == color) {
				cnt++;
				copied[ny][nx] = 'X';
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}

	// 같은 색 뿌요가 4개 이상이면 (start 포함)
	if (cnt >= 4) {
		copied[start.first][start.second] = 'X';
		memcpy(board, copied, sizeof(copied));
		return true;
	}
	else return false;
}


int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	
	int answer = 0;
	while (true) {
		int popCnt = 0; // 터지는 뿌요 개수
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != 'X' && board[i][j] != '.' 
					&& pop({ i, j })) {
					popCnt++;
				}
			}
		}
		
		// 터지는 뿌요가 존재하면
		if (popCnt > 0) {
			bomb(); // 한꺼번에 터트리기 
			answer++; 
		}
		else break;
	}

	printf("%d\n", answer);
}
