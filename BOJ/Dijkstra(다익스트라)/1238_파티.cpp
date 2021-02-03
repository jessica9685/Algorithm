// 1238_파티.cpp
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
#define INF 1000000
#define MAX 1001

int n, m, x; // n: 마을 수, m: 도로 수, x: 마을 번호
int roundTrip[MAX] = { 0, }; // 왕복 거리 배열

void dijkstra(int start, vector<vector<pair<int, int>>> map) {
	int dist[MAX];
	memset(dist, INF, sizeof(dist));

	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (auto &p : map[cur]) {
			int next = p.first;
			int next_t = p.second;
			
			if (dist[next] > next_t + cur_dist) {
				dist[next] = next_t + cur_dist;
				pq.emplace(-dist[next], next);
			}
		}
	}

	/* 정방향 + 역방향 */
	for (int i = 1; i <= n; i++) {
		roundTrip[i] += dist[i];
	}
}


int main() {
	scanf("%d %d %d", &n, &m, &x);

	vector<vector<pair<int, int>>> road(n + 1); // 정방향
	vector<vector<pair<int, int>>> roadR(n + 1); // 역방향

	for (int i = 1; i <= m; i++) {
		int start, end, t;
		scanf("%d %d %d", &start, &end, &t);
		road[start].emplace_back(end, t);
		roadR[end].emplace_back(start, t);
	}
	

	dijkstra(x, road); // 정방향
	dijkstra(x, roadR); // 역방향

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer = max(answer, roundTrip[i]);
	}

	printf("%d\n", answer);

	return 0;
}
