// 2211_네트워크_복구.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 987654321

typedef struct node {
	int end;
	int time;
};

int N, M;
vector<node> computer[MAX];
int dist[MAX];
int parent[MAX]; // 각 정점의 부모 노드 (최소 스패닝 트리를 찾기 위함)

void dijkstra(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	for (int i = 1; i <= N; i++) parent[i] = i;
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_dist = -pq.top().first;
		pq.pop();

		if (dist[cur] < cur_dist) continue;

		for (auto com : computer[cur]) {
			int next = com.end;
			int time = com.time;

			// dist의 값이 갱신되는 경우 (최소 거리인 경우)
			if (dist[next] > dist[cur] + time) {
				dist[next] = dist[cur] + time;
				parent[next] = cur; // 부모노드를 갱신
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		// 쌍방향통신
		computer[a].push_back({ b, c });
		computer[b].push_back({ a, c });
	}

	dijkstra(1);
	
	vector<pair<int, int>> ans;
	for (int i = 1; i <= N; i++) {
		if (parent[i] != i) {
			ans.push_back({ parent[i], i });
		}
	}

	printf("%d\n", (int)ans.size());
	for (auto net : ans) {
		printf("%d %d\n", net.first, net.second);
	}

	return 0;
}
