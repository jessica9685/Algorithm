// 1068_트리.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> tree;
int root, erase;
int answer = 0;

// 리프노드 세기
void dfs(int cur) {
	if (cur == erase) return;

	int child = tree[cur].size();
	// 자식이 없는 경우 (리프노드)
	if (child == 0) { 
		answer++;
		return;
	}
	// 자식이 1개인 경우
	else if (child == 1) {
		// 자식노드가 지우는 노드인 경우 현재 노드가 리프노드
		if (tree[cur][0] == erase) answer++;
		dfs(tree[cur][0]);
	}
	// 자식이 2개인 경우
	else {
		for (int i = 0; i < child; i++) dfs(tree[cur][i]);
	}
}

int main() {
	scanf("%d", &n);
	tree.resize(n);
	for (int i = 0; i < n; i++) {
		int p;
		scanf("%d", &p);
		// 루트인 경우
		if (p == -1) root = i;
		// 자식인 경우
		else tree[p].push_back(i);
	}
	scanf("%d", &erase);
	dfs(root);
	printf("%d\n", answer);
	return 0;
}
