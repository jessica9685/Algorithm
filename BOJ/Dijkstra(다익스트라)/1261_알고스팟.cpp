// 1261_알고스팟.cpp
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#define MAX 101
#define INF 10101

int n, m;
int maze[MAX][MAX] = { 0, };
int dist[MAX][MAX];
int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void dijkstra(int x, int y) {
	priority_queue<pair<int, pair<int, int>>> pq; // first: dist 배열값, second: 정점

	pq.push({ 0, { x, y } });
	dist[x][y] = 0;

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_x = pq.top().second.first;
		int cur_y = pq.top().second.second;

		pq.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + direction[i][0];
			int next_y = cur_y + direction[i][1];
			
			if (next_x > n || next_y > m || next_x <= 0 || next_y <= 0) continue; // 범위 벗어나면 continue
			if (dist[next_x][next_y] > cur_dist + maze[next_x][next_y]) { // dist 최소값 저장
				dist[next_x][next_y] = cur_dist + maze[next_x][next_y];
				pq.push({ -dist[next_x][next_y], {next_x, next_y} });
			}
		}
	}
}


int main() {
	scanf("%d %d", &m, &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	memset(dist, INF, sizeof(dist)); // dist 배열 초기화
	dijkstra(1, 1);

	printf("%d\n", dist[n][m]);

	return 0;
}
