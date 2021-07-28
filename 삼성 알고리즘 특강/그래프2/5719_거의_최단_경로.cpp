// 5719_거의_최단_경로.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define INF 987654321

typedef struct edge {
	int next;
	int len;
};

int n, m;
int S, D;
vector<edge> road[MAX];
int dist[MAX]; // 다익스트라

// 거의 최단경로를 위한 변수
vector<int> parent[MAX]; // 최단경로 정점
bool isShortest[MAX][MAX]; // 최단경로에 i->j 도로가 있으면 true

void dijkstra(int start, int end) {
	for (int i = 0; i < n; i++) dist[i] = INF;
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 도착하면 break
		if (cur == end) break;
		// 더 큰 가중치로 도착한 경우 pass
		if (cur_dist > dist[cur]) continue;
		// 다음 정점 탐색
		for (auto p : road[cur]) {
			int next = p.next;
			int next_len = p.len;

			// 최단경로에 포함된 간선이면 pass
			if (isShortest[cur][next]) continue;

			// 최단경로가 여러개일 경우 parent에 추가
			if (dist[next] == dist[cur] + next_len) {
				parent[next].push_back(cur);
			}
			// dist 최소값 갱신 후 pq에 넣기
			else if (dist[next] > dist[cur] + next_len) {
				dist[next] = dist[cur] + next_len;
				pq.push({ -dist[next], next });

				// 새로운 parent가 생겼으므로 비워주고 넣기
				parent[next].clear();
				parent[next].push_back(cur);
			}
		}
	}
}

// 최단경로에 있는 간선 제거
// 도착점부터 시작점까지 거꾸로 탐색
void backtracking(int start, int cur) {
	// 도착하면 끝
	if (start == cur) return;

	for (auto pre : parent[cur]) {
		if (!isShortest[pre][cur]) {
			isShortest[pre][cur] = true; // 최단경로 체크
			backtracking(start, pre);
		}
	}
}

int main() {
	while (true) {
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0) break;

		// isShortest, parent, road 초기화
		for (int i = 0; i < n; i++) {
			parent[i].clear();
			road[i].clear();
			for (int j = 0; j < n; j++) {
				isShortest[i][j] = false;
			}
		}


		scanf("%d %d", &S, &D);
		for (int i = 0; i < m; i++) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			road[u].push_back({ v, p });
		}

		dijkstra(S, D); // 최단경로 찾기
		backtracking(S, D); // 최단경로 제거
		dijkstra(S, D); // 거의 최단경로 찾기

		if (dist[D] == INF) printf("-1\n");
		else printf("%d\n", dist[D]);
	}

	return 0;
}
