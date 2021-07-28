// 3830_교수님은_기다리지_않는다.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000 + 1

typedef long long ll;

int n, m;
vector<int> parent; // 부모
vector<ll> dist; // 부모까지의 무게차

int find(int a) {
	// root인 경우 그대로 리턴
	if (parent[a] == a) return a;

	// root가 아닌 경우 root와의 거리를 구해 갱신
	// find가 먼저 수행되어야 a가 속한 그룹의 dist 모두 갱신 가능
	int pa = find(parent[a]);
	dist[a] += dist[parent[a]];
	return parent[a] = find(pa);
}

// a < b일 때, a가 b의 부모
// a = pa + dist[a], b = pb + dist[b]
// a + w = b
// (pa + dist[a]) + w = pb + dist[b]
// pb = pa + (dist[a] - dist[b] + w)
void unionSet(ll a, ll b, ll w) {
	int pa = find(a);
	int pb = find(b);

	// 부모가 같으면 dist 갱신할 필요 X
	if (pa == pb) return;

	// 부모가 다를 경우
	dist[pb] = dist[a] - dist[b] + w;
	parent[pb] = pa;
}

int main() {
	while (true) {
		scanf("%d %d", &n, &m);

		// 0 0을 입력받으면 종료
		if (n == 0 && m == 0) break;

		parent.resize(n + 1);
		dist.resize(n + 1); // 여기서 초기값으로 0을 주면 출력초과남;; 이유는 모름
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			dist[i] = 0; // 그냥 안전하게 일일이 초기화해주자...
		}

		while (m--) {
			char cmd;
			int a, b;
			ll w;
			scanf(" %c", &cmd);
			// 무게를 잴 때
			if (cmd == '!') {
				// b가 a보다 w만큼 무겁다
				scanf("%d %d %lld", &a, &b, &w);
				unionSet(a, b, w);
			}
			// 무게를 비교할 때
			else if (cmd == '?') {
				scanf("%d %d", &a, &b);
				// a와 b의 차이를 계산할 수 없는 경우
				if (find(a) != find(b)) {
					printf("UNKNOWN\n");
				}
				else {
					// b가 a보다 얼마나 무거운지?
					printf("%lld\n", dist[b] - dist[a]);
				}
			}
		}
	}

	return 0;
}
