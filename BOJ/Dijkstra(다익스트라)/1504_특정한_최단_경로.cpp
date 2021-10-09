// 1504_특정한_최단_경로.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 801
#define INF 987654321

typedef struct node {
	int next;
	int cost;
};

int n, e;
vector<node> graph[MAX];
bool isPossible = true;

int dijkstra(int start, int end) {
	// dist 배열 초기화
	int dist[MAX];
	for (int i = 1; i <= n; i++) dist[i] = INF;

	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		// 도착점에 도착하면 cost 리턴하고 종료
		if (cur == end) return cost;

		// 다음 정점 탐색
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].next;
			int next_c = graph[cur][i].cost;

			if (dist[next] > cost + next_c) {
				dist[next] = cost + next_c;
				pq.push({ -dist[next], next });
			}
		}
	}

	// while문을 끝까지 돌리면 경로가 없다는 뜻 -> false
	isPossible = false;
	return 0;
}

int main() {
	scanf("%d %d", &n, &e);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c }); // 역방향
	}

	int v1, v2;
	scanf("%d %d", &v1, &v2);

	int answer = min(dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n),
		dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n));

	if (!isPossible) printf("-1\n");
	else printf("%d\n", answer);
	return 0;
}

