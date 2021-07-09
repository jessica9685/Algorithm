// 13549_숨바꼭질3.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int n, k;
int dir[3] = { 1, -1, 0 };
int answer;

void dijkstra(int start, int dst) {
	int dist[MAX];
	for (int i = 0; i < MAX; i++) {
		dist[i] = MAX;
	}

	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur_dist > dist[cur]) continue;
		for (int i = 0; i < 3; i++) {
			int next;
			int time;
			if (i == 2) { // 순간이동
				next = cur * 2;
				time = cur_dist;
			}
			else {
				next = cur + dir[i];
				time = cur_dist + 1;
			}
			// 범위 벗어나면 continue
			if (next < 0 || next > 100000) continue;
			if (dist[next] > time) {
				dist[next] = time;
				pq.emplace(-dist[next], next);
			}
		}
		if (cur == dst) break;
	}

	answer = dist[dst];
}

int main() {
	scanf("%d %d", &n, &k);
	
	dijkstra(n, k);
	printf("%d\n", answer);

	return 0;
}
