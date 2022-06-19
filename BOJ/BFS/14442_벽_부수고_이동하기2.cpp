// 14442_벽_부수고_이동하기2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

typedef struct state {
	int y;
	int x;
	int cnt; // 이동 거리
	int k; // 벽 부순 횟수
};

int n, m, K;
int board[MAX][MAX];
bool visited[MAX][MAX][11]; // 벽을 k번 부쉈을 때 방문 표시
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs(int sy, int sx) {
	queue<state> q;
	visited[sy][sx][0] = true;
	q.push({ sy, sx, 1, 0 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int k = q.front().k;
		q.pop();

		// 도착하면 종료
		if (y == n && x == m) return cnt;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > m) continue;

			// 벽이 있고 아직 횟수가 남아있으면
			if (k < K && board[ny][nx] == 1) {
				if (!visited[ny][nx][k + 1]) {
					visited[ny][nx][k + 1] = true;
					q.push({ ny, nx, cnt + 1, k + 1 });
				}
			}
			// 벽이 없으면
			if (board[ny][nx] == 0) {
				if (!visited[ny][nx][k]) {
					visited[ny][nx][k] = true;
					q.push({ ny, nx, cnt + 1, k });
				}
			}
		}
	}

	// 도착할 수 없으면 -1
	return -1;
}

int main() {
	scanf("%d %d %d", &n, &m, &K);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	int answer = bfs(1, 1);
	printf("%d\n", answer);
	return 0;
}
