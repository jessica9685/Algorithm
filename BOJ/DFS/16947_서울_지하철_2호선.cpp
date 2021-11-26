// 16947_서울_지하철_2호선.cpp
// 사이클 찾기
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 3001

int n;
vector<int> graph[MAX];
int answer[MAX];
bool cycle[MAX];
bool visited[MAX];
bool is_cycle = false;

/* 순환선 찾기 */
// 각 정점의 사이클 포함 여부 표시
void dfs(int cur, int start, int edge) {
	// 사이클 찾으면 종료
	if (cur == start && edge > 1) {
		is_cycle = true;
		return;
	}

	// 다음 정점 탐색
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		// 아직 방문 안했을 때
		if (!visited[next]) dfs(next, start, edge + 1);
		// 이미 방문했을 때
		else {
			if (next == start && edge > 1) dfs(next, start, edge);
		}
		// 탐색 중 이미 사이클 찾았으면 종료
		if (is_cycle) return;
	}
}

// 각 정점과 순환선 간 거리 구하기
int bfs(int start) {
	memset(visited, false, sizeof(visited));
	visited[start] = true;
	queue<pair<int, int>> q; // first: 현재 정점, second: 거리
	q.push({ start, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		// 현재 정점이 순환선 내에 포함되어 있으면 종료
		if (cycle[cur]) return dist;

		// 다음 정점 탐색
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, dist + 1 });
			}
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 각 정점의 순환선 포함 여부 표시
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		is_cycle = false;
		dfs(i, i, 0);

		if (is_cycle) cycle[i] = true;
	}

	// 각 정점과 순환선 사이의 거리 구하기
	for (int i = 1; i <= n; i++) {
		if (cycle[i]) answer[i] = 0;
		else answer[i] = bfs(i);
	}

	// 정답 출력
	for (int i = 1; i <= n; i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
	return 0;
}
