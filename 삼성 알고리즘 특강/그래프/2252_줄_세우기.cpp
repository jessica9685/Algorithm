// 2252_줄_세우기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 32000 + 1

int n, m;
vector<int> inStudent[MAX];
vector<int> outStudent[MAX];

int main() {
	scanf("%d %d", &n, &m);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		inStudent[b].push_back(a);
		outStudent[a].push_back(b);
	}

	queue<int> q;
	vector<int> inDegree(n + 1, 0);
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		inDegree[i] = inStudent[i].size();
		// 진입차수가 0인 정점 큐에 삽입
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		result.push_back(node);
		q.pop();

		// 연결된 간선 제거
		for (int i = 0; i < outStudent[node].size(); i++) {
			inDegree[outStudent[node][i]]--; 
			// 만약 진입차수가 0이면 큐에 삽입
			if (inDegree[outStudent[node][i]] == 0) q.push(outStudent[node][i]);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
