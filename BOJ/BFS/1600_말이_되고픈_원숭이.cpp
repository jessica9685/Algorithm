// 1600_말이_되고픈_원숭이.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct state {
	int y;
	int x;
	int cnt; // 이동 횟수
	int k; // 말로 이동한 횟수
};

int K, n, m;
int board[200][200];
int monkey[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int horse[8][2] = { 
	{-1, -2}, {-2, -1},
	{-2, 1}, {-1, 2},
	{1, -2}, {2, -1},
	{2, 1}, {1, 2}
};

int bfs(int sy, int sx) {
	// 말로 k번 뛰었을 때 방문표시
	bool visited[200][200][31] = { false, };
	visited[sy][sx][0] = true;
	queue<state> q;
	q.push({ sy, sx, 0, 0 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int k = q.front().k;
		q.pop();

		if (y == n - 1 && x == m - 1) return cnt;

		// 말로 이동하기
		if (k < K) {
			for (int i = 0; i < 8; i++) {
				int ny = y + horse[i][0];
				int nx = x + horse[i][1];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				// 이미 방문했거나 장애물 있으면 패스
				if (visited[ny][nx][k + 1] || board[ny][nx] == 1) continue;

				visited[ny][nx][k + 1] = true;
				q.push({ ny, nx, cnt + 1, k + 1 });
			}
		}

		// 원숭이로 이동하기
		for (int i = 0; i < 4; i++) {
			int ny = y + monkey[i][0];
			int nx = x + monkey[i][1];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			// 이미 방문했거나 장애물 있으면 패스
			if (visited[ny][nx][k] || board[ny][nx] == 1) continue;
			
			visited[ny][nx][k] = true;
			q.push({ ny, nx, cnt + 1, k });
		}
	}

	// 도착할 수 없으면 -1
	return -1;
}

int main() {
	scanf("%d", &K);
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	int answer = bfs(0, 0);
	printf("%d\n", answer);
	return 0;
}
