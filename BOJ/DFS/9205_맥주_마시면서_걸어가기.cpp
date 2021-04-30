// 9205_맥주_마시면서_걸어가기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 102

int T; // test case
int n;

vector<int> graph[MAX];
bool visited[MAX];

int dist(pair<int, int> a, pair<int, int> b) {
	int x = abs(a.first - b.first);
	int y = abs(a.second - b.second);

	return x + y;
}

void dfs(int node) {
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) dfs(next);
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		// 초기화
		for (int i = 0; i < MAX; i++) graph[i].clear();
		memset(visited, false, sizeof(visited));

		scanf("%d", &n);

		vector<pair<int, int>> loc;
		for (int i = 0; i < n + 2; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			loc.push_back({ x, y });
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				// 맥주 20개 내로 편의점 갈 수 있으면
				if (dist(loc[i], loc[j]) <= 50 * 20) {
					// 그래프 연결
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		dfs(0);
		if (visited[n + 1]) printf("happy\n");
		else printf("sad\n");
	}
}
