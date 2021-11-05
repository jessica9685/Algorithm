// 1707_이분_그래프.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 20001

int T, v, e;
vector<int> graph[MAX];
int visited[MAX]; // 0이면 아직 집합 X / 1이면 red / 2이면 blue

void bfs(int start, int color) {
	visited[start] = color;
	queue<pair<int, int>> q;
	q.push({ start, color });

	while (!q.empty()) {
		int cur = q.front().first;
		int curColor = q.front().second;
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			if (!visited[graph[cur][i]]) {
				visited[graph[cur][i]] = 3 - curColor;
				q.push({ graph[cur][i], 3 - curColor });
			}
		}
	}
}

bool isBipartiteGraph() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			// 인접한 정점의 색이 같으면 false
			if (visited[i] == visited[next]) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		// 초기화
		for (int i = 0; i < MAX; i++) graph[i].clear();
		for (int i = 0; i < MAX; i++) visited[i] = 0;

		scanf("%d %d", &v, &e);
		for (int i = 0; i < e; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		// 각 정점의 색 정하기
		for (int i = 1; i <= v; i++) {
			if (!visited[i]) bfs(i, 1);	
		}

		if (!isBipartiteGraph())  printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
