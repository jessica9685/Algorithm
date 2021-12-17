// 13023_ABCDE.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 2001

int n, m;
vector<int> friends[MAX];
vector<bool> visited;
bool answer = false;

void dfs(int cur, int depth) {
	// 현재 노드 방문
	visited[cur] = true;

	// 깊이가 4이면 종료
	if (depth == 4) {
		answer = true;
		return;
	}

	for (auto next : friends[cur]) {
		if (answer) return; // 이미 true이면 종료
		if (!visited[next]) { // 아직 방문 안했으면
			dfs(next, depth + 1);
		}
	}

	// 되돌아오기
	visited[cur] = false;
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	visited.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	// 0 ~ n - 1까지의 친구 관계 탐색
	for (int i = 0; i < n; i++) {
		fill(visited.begin(), visited.end(), false);
		dfs(i, 0);

		// ABCDE를 찾았으면 종료
		if (answer) {
			printf("1\n");
			return 0;
		}
	}

	// ABCDE를 못찾았으면 0
	printf("0\n");
	return 0;
}
