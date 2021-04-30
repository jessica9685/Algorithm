// 12851_숨바꼭질2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000 + 1

int n, k;
bool visited[MAX];
int dx[2] = { 1, -1 };
int mini = 0;
int cnt = 0;

void bfs(int start, int end) {
	visited[start] = true;
	queue<pair<int, int>> q;
	q.push({ start, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		// 여기서 방문표시해야 경우의 수 고려 가능
		visited[cur] = true;

		if (cur == end) {
			if (mini == 0) { // 처음 목적지 도달
				mini = time;
				cnt++;
			}
			else { // 두번 이상 목적지 도달
				if (time == mini) cnt++;
			}
		}

		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 2) next = cur * 2;
			else next = cur + dx[i];

			if (next < 0 || next >= MAX) continue;
			if (!visited[next]) {
				q.push({ next, time + 1 });
				// 여기서 방문표시하면 다른 루트는 고려하지 않게 됨
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);

	memset(visited, false, sizeof(visited));
	bfs(n, k);

	printf("%d\n", mini);
	printf("%d\n", cnt);
}
