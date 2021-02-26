// 2206_벽_부수고_이동하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

typedef struct state {
	int x;
	int y;
	int wall;
};

int n, m; // n행 m열
int map[MAX][MAX];
int visited[MAX][MAX][2] = { 0, }; // 0: 벽을 부수지 않음, 1: 벽을 부숨
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int bfs(int sa, int sb) {
	visited[sa][sb][0] = 1;

	queue<state> q;
	q.push({ sa, sb, 0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall;
		q.pop();

		// 도착했을 경우
		if (x == n && y == m) return visited[x][y][wall];

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

			// 이미 방문한 경우
			if (visited[nx][ny][wall] > 0) continue;

			// 벽이 있고, 아직 안뚫은 경우
			if (map[nx][ny] == 1 && wall == 0) {
				visited[nx][ny][1] = visited[x][y][0] + 1;
				q.push({ nx, ny, 1 });
			}

			// 벽이 없는 경우
			else if (map[nx][ny] == 0) {
				visited[nx][ny][wall] = visited[x][y][wall] + 1;
				q.push({ nx, ny, wall });
			}
		}
	}

	// 경로가 없는 경우
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int answer = bfs(1, 1);
	printf("%d\n", answer);
	return 0;
}
