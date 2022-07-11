// 2234_성곽.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
// 서(1) 북(2) 동(4) 남(8)
int castle[50][50];
bool visited[50][50] = { false, };
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

// 방의 넓이 구하기
int bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	visited[sy][sx] = true;
	q.push({ sy, sx });

	int result = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		result++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 경계 밖이면 패스
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			// 해당 방향에 벽이 있으면 패스
			if ((castle[y][x] & (1 << i)) == (1 << i)) continue;
			// 이미 방문했으면 패스
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	return result;
}

int main() {
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &castle[i][j]);
		}
	}

	// 1. 방 개수 & 2. 가장 넓은 방의 넓이
	int room = 0; // 방 개수
	int max_area = 0; // 방 넓이
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 아직 방문 안했으면 방문
			if (!visited[i][j]) {
				max_area = max(max_area, bfs(i, j));
				room++;
			}
		}
	}
	printf("%d\n", room);
	printf("%d\n", max_area);

	// 3. 하나의 벽을 제거해 얻을 수 있는 가장 넓은 방의 크기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int d = 0; d < 4; d++) {
				// 벽 있으면 제거
				if ((castle[i][j] & (1 << d)) == (1 << d)) {
					// visited 초기화
					memset(visited, false, sizeof(visited));
					castle[i][j] &= ~(1 << d); // 벽 제거
					// 최대 방 넓이 계산
					max_area = max(bfs(i, j), max_area);
					// 제거한 벽 원래대로 되돌리기
					castle[i][j] |= (1 << d);
				}
			}
		}
	}
	printf("%d\n", max_area);
	return 0;
}
