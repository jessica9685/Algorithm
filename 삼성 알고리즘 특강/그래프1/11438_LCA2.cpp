// 11438_LCA2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000 + 1

int n, m, k;
vector<int> tree[MAX];
int depth[MAX]; // 각 정점의 깊이
// n의 최대값이 10만이므로, k의 최대는 17
int parent[17][MAX]; // parent[k][v] : 정점 v의 2^k번째 조상

// 모든 정점의 depth 구하기
void dfs(int node, int cnt) {
	// 본인의 depth 저장
	depth[node] = cnt;

	// 자식들의 depth 저장
	for (int i = 0; i < tree[node].size(); i++) {
		int child = tree[node][i];
		
		// 깊이를 모르면
		if (depth[child] == 0) {
			parent[0][child] = node; // child의 첫번째 부모는 node
			dfs(child, cnt + 1);
		}
	}
}

// 각 정점의 부모 구하기
void fillParent() {
	// parent[0][n]은 이미 채워짐
	for (int i = 1; i < k; i++) { // 2^k 번째 조상
		for (int j = 1; j <= n; j++) { // 정점
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}

// 최소 공통 조상 구하기
int lca(int a, int b) {
	/* 1. depth 맞추기 */
	// depth[a] >= depth[b]가 되도록 a, b 조정
	if (depth[a] < depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}

	// depth가 더 깊은 a를 2^k만큼 점프하여 b의 depth로 맞춰줌
	for (int i = k - 1; i >= 0; i--) {
		if (depth[a] - depth[b] >= (int)pow(2, i)) {
			a = parent[i][a]; // a의 2^i번째 조상으로 갱신
		}
	}

	// 2. depth를 맞춘 결과 a, b가 같다면 리턴
	if (a == b) return a;

	// 3. a, b가 같지 않다면 a와 b를 공통 조상 바로 아래까지 올림
	for (int i = k - 1; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

int main() {
	scanf("%d", &n);

	// 2^k > n인 k 찾기
	k = 0;
	for (int i = 1; i <= n; i *= 2) k++;

	// tree 초기화
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		// 양방향
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	// depth 채우기
	dfs(1, 1);
	
	// 부모 채우기
	fillParent();

	// LCA 구하기
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}

	return 0;
}
