// 1922_네트워크_연결.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000 + 1

struct edge {
	int start, end; // 정점
	int cost;
};

int n, m;
vector<edge> computer;
vector<int> parent;

// priority queue의 정렬 함수는 일반 comp랑 반대
// cost 오름차순 정렬
struct comp {
	bool operator()(edge a, edge b) {
		return a.cost > b.cost;
	}
};

// 부모집합 찾기
int find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = find(parent[a]);
	}
}

// 합집합
void unionSet(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	parent[pb] = pa;
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	
	// cost 오름차순 정렬 우선순위 큐
	priority_queue<edge, vector<edge>, comp> pq;
	// 부모 초기화
	parent.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) parent[i] = i;

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		computer.push_back({ a, b, c });
		pq.push({ a, b, c });
	}

	int cnt = 0; // 연결된 간선 개수
	int result = 0; // 최소 비용
	while (!pq.empty()) {
		edge cur = pq.top();
		pq.pop();
		
		// 가지치기 (간선을 모두 골랐으면 끝)
		if (cnt == n - 1) break;
		// 같은 컴퓨터는 연결 X
		if (cur.start == cur.end) continue;
		// 연결되어있지 않은 경우
		if (find(cur.start) != find(cur.end)) {
			cnt++;
			unionSet(cur.start, cur.end);
			result += cur.cost;
		}
	}

	printf("%d\n", result);
	return 0;
}
