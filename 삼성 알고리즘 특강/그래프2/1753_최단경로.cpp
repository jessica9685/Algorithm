// 1753_최단경로.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 20000 + 1
#define INF 3000001

typedef struct edge {
	int next; // 다음 정점
	int w; // 가중치
};

int v, e;
vector<edge> graph[MAX];

void dijkstra(int start) {
	vector<int> dist(v + 1, INF);
	vector<bool> visited(v + 1, false);

	dist[start] = 0;

	// first : dist, second : 다음 정점
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ dist[start], start });

	while (!pq.empty()) {
		int cur_dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 만약 이미 방문한 정점이면 pass 
		// why? 서로 다른 두 정점 사이에 여러 개의 간선이 있을 수 있기 때문
		if (visited[cur]) continue;

		visited[cur] = true; // 현재 정점 방문

		// 더 큰 가중치로 도착한 경우 pass
		if (cur_dist > dist[cur]) continue;

		// 다음 최소 정점 넣기
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].next;
			int next_w = graph[cur][i].w;

			if (dist[next] > dist[cur] + next_w) {
				dist[next] = dist[cur] + next_w;
				pq.push({ dist[next], next });
			}
		}
	}

	// 각 정점까지의 최단경로 출력
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}

int main() {
	scanf("%d %d", &v, &e);
	int start;
	scanf("%d", &start);
	while (e--) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		graph[a].push_back({ b, w });
	}

	dijkstra(start);

	return 0;
}
