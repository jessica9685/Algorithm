// 1799_비숍.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
int board[10][10];
bool visited[10][10];
// 대각선 방향 4개
int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { 1, -1, 1, -1 };
vector<pair<int, int>> bishop;
int white = 0, black = 0;

// 비숍을 둘 수 있는 곳이면 true
bool isPossible(int y, int x) {
	for (int i = 1; i < n; i++) {
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d] * i;
			int nx = x + dx[d] * i;

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx]) return false;
		}
	}
	return true;
}

// idx: bishop 좌표의 인덱스, cnt: 위치시킨 비숍 개수
// color: 0(black), 1(white)
void dfs(int idx, int cnt, int color) {
	// 각 칸에 놓을 수 있는 비숍의 최대값 갱신 
	if (color == 0) black = max(black, cnt);
	else white = max(white, cnt);

	// 비숍을 놓을 위치 탐색
	for (int i = idx; i < bishop.size(); i++) {
		int y = bishop[i].first;
		int x = bishop[i].second;

		if (color == 0) { // black
			// 흰칸은 건너뛰기
			if (y % 2 == 0 && x % 2 == 1) continue;
			if (y % 2 == 1 && x % 2 == 0) continue;
		}
		else { // white
			// 검은칸은 건너뛰기
			if (y % 2 == 0 && x % 2 == 0) continue;
			if (y % 2 == 1 && x % 2 == 1) continue;
		}

		// 아직 방문하지 않았고, 비숍을 놓을 수 있으면
		if (!visited[y][x] && isPossible(y, x)) {
			visited[y][x] = true;
			dfs(i + 1, cnt + 1, color);
			visited[y][x] = false; // 백트래킹
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1) bishop.push_back({ i, j });
		}
	}

	dfs(0, 0, 0); // 검은색 칸
	dfs(0, 0, 1); // 흰색 칸

	printf("%d\n", black + white);
	return 0;
}
