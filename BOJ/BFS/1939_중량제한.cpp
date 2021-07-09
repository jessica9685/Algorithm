// 1939_중량제한.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

typedef long long ll;

int n, m;
int src, dst;
vector<pair<int, ll>> bridge[MAX];
ll answer;

bool bfs(int weight) {
	bool visited[MAX] = { false, };
	queue<int> q;
	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 도착하면 true 리턴
		if (cur == dst) return true;

		for (auto p : bridge[cur]) {
			int next = p.first;
			int limit = p.second;

			if (visited[next]) continue; // 이미 방문했으면 continue
			if (limit >= weight) { // 물품 무게가 다리 중량 제한보다 작으면
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	ll left = 1000000000;
	ll right = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		bridge[a].push_back({ b, c });
		bridge[b].push_back({ a, c });
		right = max(right, c);
		left = min(left, c);
	}

	scanf("%d %d", &src, &dst);

	// 이분탐색
	while (left <= right) {
		int mid = (left + right) / 2;

		// mid 무게로 운반 가능하면
		if (bfs(mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	answer = right;
	printf("%lld\n", answer);

	return 0;
}
