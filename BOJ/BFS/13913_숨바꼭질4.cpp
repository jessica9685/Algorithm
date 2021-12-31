// 13913_숨바꼭질4.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int n, k;
bool visited[MAX];
int dx[2] = { 1, -1 };
int minSec = 0;
vector<int> path;
int parent[MAX]; // 해당 지점 방문 직전의 위치

void bfs(int start, int end) {
	memset(visited, false, sizeof(visited));
	visited[start] = true;
	queue<pair<int, int>> q; // first: 현재 정점, second: 이동 시간
	q.push({ start, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		// 목적지 도착한 경우 break
		if (cur == end) {
			minSec = time; // 최소 시간
			int loc = cur; // 현재 지점
			// 이전에 방문한 지점을 거슬러 올라감
			while (loc != start) {
				path.push_back(loc);
				loc = parent[loc];
			}
			path.push_back(start);
			break;
		}

		// 다음으로 이동
		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 2) next = cur * 2;
			else next = cur + dx[i];

			// 범위 벗어나면 넘어감
			if (next < 0 || next >= MAX) continue;
			if (!visited[next]) { // 아직 방문 안한 곳이면
				visited[next] = true; // 방문표시
				parent[next] = cur; // 직전 지점 표시
				q.push({ next, time + 1 });
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	bfs(n, k);

	printf("%d\n", minSec);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("\n");
	return 0;
}
