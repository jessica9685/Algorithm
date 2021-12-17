// 2668_숫자고르기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int n;
int group[MAX];
bool visited[MAX];
vector<int> selected;

// 사이클 찾기
void dfs(int cur, int start) {
	// 아직 방문 안했으면
	if (!visited[cur]) {
		visited[cur] = true;
		dfs(group[cur], start);
	}
	// 사이클이 발생하면
	else if (cur == start) {
		selected.push_back(start);
		return;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		group[i] = num;
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, i);
	}

	int s = selected.size();
	printf("%d\n", s);
	for (int i = 0; i < s; i++) {
		printf("%d\n", selected[i]);
	}
	return 0;
}
