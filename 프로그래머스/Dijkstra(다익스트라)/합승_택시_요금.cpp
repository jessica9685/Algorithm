// 2021_카카오 : 합승_택시_요금.cpp
// 정확성 50.0, 효율성 30.0 (시간초과)
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 20000001

int dist[201];
vector<pair<int, int>> map[201];

int dijkstra(int start, int dst) {
	memset(dist, INF, sizeof(dist));

	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (auto& p : map[cur]) {
			int next = p.first;
			int next_t = p.second;

			if (dist[next] > next_t + cur_dist) {
				dist[next] = next_t + cur_dist;
				pq.emplace(-dist[next], next);
			}
		}
	}

	return dist[dst];
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	for (auto& p : fares) {
		int start = p[0];
		int end = p[1];
		int cost = p[2];
		map[start].push_back({ end, cost });
		map[end].push_back({ start, cost });
	}

	int answer = dijkstra(s, a) + dijkstra(s, b);
	for (int i = 1; i <= n; i++) {
		if (s != i) {
			int route = dijkstra(s, i) + dijkstra(i, a) + dijkstra(i, b);
			answer = min(answer, route);
		}
	}

	return answer;
}
