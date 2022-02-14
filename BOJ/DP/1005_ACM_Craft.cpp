// 1005_ACM_Craft.cpp
// DP + 위상정렬
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int T, n, k, w;
int times[MAX]; // 건설 시간
vector<int> order[MAX]; // 건설 순서
int inDegree[MAX] = { 0, }; // 진입 차수
int dp[MAX] = { 0, }; // 각 건물의 최소 건설 시간

// 위상 정렬
int topology_sort() {
	queue<int> q;
	// 진입차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 다음 건물 정하기
		for (auto next : order[cur]) {
			// 다음 건물 최소 건설 시간 갱신
			dp[next] = max(dp[next], dp[cur] + times[next]);
			// 진입차수가 0인 노드 큐에 push
			if (--inDegree[next] == 0) q.push(next);
		}
	}

	return dp[w];
}

int main() {
	scanf("%d", &T); // test case
	while (T--) {
		scanf("%d %d", &n, &k); // 건물 개수, 건설순서 규칙 개수	
		for (int i = 1; i <= n; i++) { // 건설 시간
			scanf("%d", &times[i]);
			dp[i] = times[i];
		}
		for (int i = 0; i < k; i++) { // 건설 순서
			int x, y;
			scanf("%d %d", &x, &y);
			order[x].push_back(y);
			inDegree[y]++; // 진입차수 증가
		}
		scanf("%d", &w); // 목표 건물

		int ans = topology_sort();
		printf("%d\n", ans); // 출력

		// 초기화
		for (int i = 1; i <= n; i++) {
			times[i] = 0;
			dp[i] = 0;
			inDegree[i] = 0;
			order[i].clear();
		}
	}
	return 0;
}
