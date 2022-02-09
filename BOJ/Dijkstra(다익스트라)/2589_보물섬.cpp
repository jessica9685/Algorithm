// 2589_보물섬.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 987654321

typedef struct node {
	int y;
	int x;
	int cost;
};

struct cmp { // 거리 오름차순 정렬
	bool operator()(node a, node b) {
		return a.cost > b.cost;
	}
};

int n, m;
char board[MAX][MAX];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int dijkstra(int sy, int sx) {
	// dist 배열 초기화 
	int dist[MAX][MAX];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) dist[i][j] = INF;
	}

	priority_queue<node, vector<node>, cmp> pq;
	pq.push({ sy, sx, 0 });
	dist[sy][sx] = 0;

	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			// 범위 벗어나면 패스
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			// 다음 정점이 바다면 패스
			if (board[ny][nx] == 'W') continue;
			// 최단거리 갱신
			if (dist[ny][nx] > cur.cost + 1) {
				dist[ny][nx] = cur.cost + 1;
				pq.push({ ny, nx, dist[ny][nx] });
			}
		}
	}

	// 각 정점과의 거리 중 최장거리 찾기
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] != INF && dist[i][j] > res) {
				res = dist[i][j];
			}
		}
	}

	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	int ans = 0; // 최단거리 중 최대거리
	// 각 육지에 대한 최대거리를 찾음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'W') continue;
			int curDist = dijkstra(i, j);
			ans = max(ans, curDist);
		}
	}

	printf("%d\n", ans);
	return 0;
}
