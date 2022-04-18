// 1600_말이_되고픈_원숭이.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 200

int K, n, m;
int ground[MAX][MAX];
bool visited[MAX][MAX][31] = { false, }; // 말로 k번 뛰었을 때 방문 표시
int horse[8][2] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2} };
int monkey[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int bfs(int sy, int sx) {
	// first: 현재 좌표, second: 말로 뛴 횟수, 전체 횟수
	queue<pair<pair<int, int>, pair<int, int>>> q;
	visited[sy][sx][0] = true;
	q.push({ {sy, sx}, {0, 0} });

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int k = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (y == n - 1 && x == m - 1) return cnt;

		// 말로 뛰기
		if (k < K) {
			for (int i = 0; i < 8; i++) {
				int ny = y + horse[i][0];
				int nx = x + horse[i][1];

				// 범위 벗어나면 패스
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				// 장애물이거나 이미 방문했으면 패스
				if (visited[ny][nx][k + 1] || ground[ny][nx] == 1) continue;
				
				visited[ny][nx][k + 1] = true;
				q.push({ {ny, nx}, {k + 1, cnt + 1} });
			}
		}

		// 그냥 걷기
		for (int i = 0; i < 4; i++) {
			int ny = y + monkey[i][0];
			int nx = x + monkey[i][1];

			// 범위 벗어나면 패스
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			// 장애물이거나 이미 방문했으면 패스
			if (visited[ny][nx][k] || ground[ny][nx] == 1) continue;
			
			visited[ny][nx][k] = true;
			q.push({ {ny, nx}, {k, cnt + 1} });
		}
	}

	return -1;
}

int main() {
	scanf("%d", &K);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ground[i][j]);
		}
	}
	int ans = bfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
