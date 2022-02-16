// 1766_문제집.cpp
// 위상정렬
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 32001

int n, m;
vector<int> test[MAX]; // 문제 푸는 순서 정보
vector<int> order; // 정답
int indegree[MAX] = { 0, }; // 진입차수

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; // a -> b
		scanf("%d %d", &a, &b);
		test[a].push_back(b);
		indegree[b]++;
	}

	// 진입차수가 2 이상인 경우 오름차순 정렬
	for (int i = 1; i <= n; i++) {
		if (indegree[i] > 1) {
			sort(test[i].begin(), test[i].end());
		}
	}

	// 우선순위 큐 (쉬운 문제부터) (오름차순)
	priority_queue<int, vector<int>, greater<int>> pq;
	// 진입차수가 0인 문제 push
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		order.push_back(cur); // 현재 정점 경로에 추가

		// 다음 정점 탐색
		for (auto next : test[cur]) {
			// 진입차수가 0이면 push
			if (--indegree[next] == 0) {
				pq.push(next);
			}
		}
	}

	// 정답 출력
	for (auto q : order) {
		printf("%d ", q);
	}
	printf("\n");
	return 0;
}
