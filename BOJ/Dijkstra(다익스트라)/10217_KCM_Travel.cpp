// 10217_KCM_Travel.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 10000001

typedef struct info {
	int v; // 정점
	int cost; // 비용
	int time; // 시간
};

int n, m, k;
int answer;
vector<vector<info>> ticket;
int dist[MAX][10001]; // dist[정점][사용한 비용] = 걸린 시간

// 거리(시간) 오름차순 정렬
struct cmp {
	bool operator()(info a, info b) {
		return a.time > b.time;
	}
};

void dijkstra(int s) {
	// dist 배열 초기화
	for (int i = 1; i <= n; i++) { // 1 ~ n
		for (int j = 0; j <= m; j++) { // 0 ~ m
			dist[i][j] = INF;
		}
	}

	priority_queue<info, vector<info>, cmp> pq;
	dist[s][0] = 0;
	info start;
	start.v = s;
	start.cost = 0;
	start.time = 0;

	pq.push(start);

	while (!pq.empty()) {
		info cur = pq.top();
		pq.pop();

		if (dist[cur.v][cur.cost] < start.cost) continue;
		for (info t : ticket[cur.v]) {
			info next;
			next.v = t.v; // 다음 정점
			next.cost = cur.cost + t.cost; // 비용
			next.time = dist[cur.v][cur.cost] + t.time; // 걸린 시간

			// 최대 비용을 넘어가면 continue
			if (next.cost > 10000) continue;
			if (dist[next.v][next.cost] > next.time) {
				dist[next.v][next.cost] = next.time;
				pq.push(next);
			}
		}
	}

	// n까지 가는데 걸리는 최소 거리 구하기
	for (int i = 0; i <= m; i++) {
		answer = min(answer, dist[n][i]);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &k);
		ticket.clear();
		ticket.resize(n + 1);

		for (int i = 0; i < k; i++) {
			int u;
			info t;
			scanf("%d %d %d %d", &u, &t.v, &t.cost, &t.time);
			ticket[u].push_back(t);
		}

		answer = INF;
		dijkstra(1);
		if (answer != INF) printf("%d\n", answer);
		else printf("Poor KCM\n");
	}

	return 0;
}
