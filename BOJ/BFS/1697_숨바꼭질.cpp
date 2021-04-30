// 1697_숨바꼭질.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000 + 1

int n, k;
int dx[2] = { 1, -1 };
bool visited[MAX];
int ans;

int main() {
	scanf("%d %d", &n, &k);
	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;
	visited[n] = true;
	q.push({ n, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == k) {
			ans = cnt;
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 2) next = cur * 2;
			else next = cur + dx[i];

			if (next < 0 || next >= MAX) continue;
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}

	printf("%d\n", ans);
}
