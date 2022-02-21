// 5719_거의_최단_경로.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 501
#define INF 987654321

typedef struct edge {
	int next;
	int len;
};

int n, m; // 장소, 도로 수
int s, d; // 시작점, 도착점
vector<edge> roads[MAX];
int dist[MAX];

// 경로 추적을 위한 부모 노드
// 최단 경로는 여러개일 수 있으므로 vector로 선언
vector<int> parent[MAX]; 
bool isShortest[MAX][MAX]; // i->j가 최단 경로에 포함되면 true

void dijkstra(int start, int end) {
	// 초기화
	for (int i = 0; i < n; i++) dist[i] = INF;
	dist[start] = 0;

	priority_queue <pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_dist = -pq.top().first;
		pq.pop();

		// 도착하면 break
		if (cur == end) break;
		// 더 큰 가중치로 도착한 경우 pass
		if (cur_dist > dist[cur]) continue;

		// 다음 정점 탐색
		for (auto road : roads[cur]) {
			int next = road.next;
			int nlen = road.len;

			// 최단경로에 포함된 간선이면 패스
			// 2번째 다익스트라 실행 시 적용
			if (isShortest[cur][next]) continue;

			// 최단경로가 여러개일 경우 parent에 추가
			// 1번째 다익스트라 수행 후 경로 추적을 위해 사용
			if (dist[next] == dist[cur] + nlen) {
				parent[next].push_back(cur);
			}

			// dist 최소값 갱신
			if (dist[next] > dist[cur] + nlen) {
				dist[next] = dist[cur] + nlen;
				pq.push({ -dist[next], next });

				// 최단경로가 갱신되었으므로 parent도 갱신
				parent[next].clear();
				parent[next].push_back(cur);
			}
		}
	}
}

// 최단경로에 있는 간선 제거
// 도착점부터 시작점까지 역추적
void backtracking(int start, int cur) {
	// 도착하면 종료
	if (start == cur) return;

	// 역추적
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
		// 0이 2개 입력되면 종료
		if (n == 0 && m == 0) break;
		
		// roads, parent, isShortest 초기화
		for (int i = 0; i < n; i++) {
			roads[i].clear();
			parent[i].clear();
			for (int j = 0; j < n; j++) {
				isShortest[i][j] = false;
			}
		}

		scanf("%d %d", &s, &d);
		while (m--) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			roads[u].push_back({ v, p });
		}

		dijkstra(s, d); // 최단경로 찾기
		backtracking(s, d); // 최단경로 제거
		dijkstra(s, d); // 거의 최단경로 찾기

		int ans = dist[d];
		// 거의 최단 경로가 없으면 -1
		if (ans == INF) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}
