// 2637_장난감_조립.cpp
// 위상정렬 + DP
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int n, m;
int indegree[MAX]; // 진입차수 (n -> n-1 ...)
vector<pair<int, int>> product[MAX];
int part[MAX]; // 완제품 만드는데 필요한 각 부품 개수
vector<int> ans;

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	while (m--) {
		int x, y, k; // x <- y*k
		scanf("%d %d %d", &x, &y, &k);
		product[x].push_back({ y, k });
		indegree[y]++;
	}

	// 위상정렬
	queue<int> q;
	q.push(n); // 완제품 큐에 push
	part[n] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 직전 부품이 존재하지 않으면
		if (product[cur].empty()) {
			// 기본 부품에 추가
			ans.push_back(cur);
		}

		// 직전 부품 탐색
		for (auto prev : product[cur]) {
			// 필요한 부품 개수 갱신
			part[prev.first] += part[cur] * prev.second;
			// 진입차수가 0이면
			if (--indegree[prev.first] == 0) {
				q.push(prev.first);
			}
		}
	}

	// 기본부품 오름차순 정렬
	sort(ans.begin(), ans.end());
	for (auto cur : ans) {
		printf("%d %d\n", cur, part[cur]);
	}
	return 0;
}
