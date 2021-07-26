// 2252_줄_세우기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 32000 + 1

int n, m;
vector<int> student[MAX];

int main() {
	scanf("%d %d", &n, &m);

	vector<int> inDegree(n + 1, 0);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		student[a].push_back(b);
		inDegree[b]++;
	}

	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		// 진입차수가 0인 정점 큐에 삽입
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		result.push_back(node);
		q.pop();

		// 연결된 간선 제거
		for (int i = 0; i < student[node].size(); i++) {
			inDegree[student[node][i]]--; 
			// 만약 진입차수가 0이면 큐에 삽입
			if (inDegree[student[node][i]] == 0) q.push(student[node][i]);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
