// SWEA : 1249_보급로.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 99999
typedef long long ll;

typedef struct point {
	int x;
	int y;
	int cost;
};

/* cost 오름차순 정렬 */
struct cmp {
	bool operator()(point& a, point& b) {
		return a.cost > b.cost;
	}
};

int T;
int n; // size of map
int maps[MAX][MAX];
int dist[MAX][MAX];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int mini;

int bfs(int a, int b) {
	dist[a][b] = 0;

	priority_queue<point, vector<point>, cmp> pq;
	point start;
	start.x = a;
	start.y = b;
	start.cost = 0;
	pq.push(start);

	while (!pq.empty()) {
		point cur = pq.top();
		pq.pop();

		// 도착하면
		if (cur.x == n - 1 && cur.y == n - 1) break;

		// 현재까지의 cost가 최소값보다 크면 pass
		if (cur.cost > dist[cur.x][cur.y]) continue;

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dir[i][0];
			int ny = cur.y + dir[i][1];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (dist[nx][ny] > dist[cur.x][cur.y] + maps[nx][ny]) {
				point next;
				next.x = nx;
				next.y = ny;
				next.cost = dist[cur.x][cur.y] + maps[nx][ny];
				dist[nx][ny] = next.cost;
				pq.push(next);
			}
		}
	}

	return dist[n - 1][n - 1];
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &maps[i][j]);
				dist[i][j] = INF;
			}
		}
		
		int answer = bfs(0, 0);

		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
