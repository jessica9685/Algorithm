// 16928_뱀과_사다리_게임.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[101];
int ladder[101];
int snake[101];
int answer = 10000;

void bfs(int start) {
	bool visited[101] = { false, };
	visited[start] = true;
	queue<pair<int, int>> q;
	q.push({ start, 0 });

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int cube = 1; cube <= 6; cube++) {
			int next = cur + cube;
			if (ladder[next] != 0) next = ladder[next];
			else if (snake[next] != 0) next = snake[next];
			
			// 100을 넘어가거나 이미 방문했으면 패스
			if (next > 100 || visited[next]) continue;
			// 100에 도착하면
			else if (next == 100) {
				answer = min(answer, cnt + 1);
				break;
			}
			// 아직 도착하지 못하면
			else {
				visited[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}
}

int main() {
	// 보드판: 1 ~ 100 채우기
	for (int i = 1; i <= 100; i++) board[i] = i;
	
	scanf("%d %d", &n, &m);
	// 사다리
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ladder[x] = y;
	}
	// 뱀
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		snake[u] = v;
	}

	bfs(1);
	printf("%d\n", answer);
	return 0;
}
