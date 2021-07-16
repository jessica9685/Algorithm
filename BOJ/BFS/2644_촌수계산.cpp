// 2644_촌수계산.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int n, m;
int a, b; // 계산해야할 촌수

// 부모 - 자식간 거리를 1로 생각 (부모 - 자식이 간선)
vector<int> graph[MAX]; 

// start와 다른 사람들 사이의 촌수 배열
int dist[MAX] = { 0, }; 

int bfs(int start, int end) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == end) return dist[end];

		int s = graph[cur].size();
		for (int i = 0; i < s; i++) {
			int next = graph[cur][i];

			// next와의 관계가 계산되지 않았으면
			if (!dist[next]) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}

	// 친척이 아니면
	return -1;
}

int main() {
	scanf("%d", &n); // 사람 수
	scanf("%d %d", &a, &b); 

	// 그래프 설정
	scanf("%d", &m); // 관계 수
	for (int i = 0; i < m; i++) { // 관계
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int ans = bfs(a, b);
	printf("%d\n", ans);
	return 0;
}
