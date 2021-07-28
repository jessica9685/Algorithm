// 11657_타임머신.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
#define MAX 501

typedef long long ll;
typedef struct Edge {
	int start;
	int end;
	int time;
};

int n, m;
vector<Edge> bus;
ll dist[MAX];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bus.push_back({ a, b, c });
	}
	
	// dist 초기화
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[1] = 0; // 1번부터 출발

	// 모든 간선을 n-1번 순회
	for (int i = 1; i <= n - 1; i++) {
		// 간선리스트 순회
		for (auto cur : bus) {
			// 시작점의 dist가 INF면 아직 갈 수 없음
			if (dist[cur.start] == INF) continue;
			// 도착점의 dist = 기존값과 시작점 dist + 도착점까지 걸리는 시간의 최소값
			if (dist[cur.end] > dist[cur.start] + cur.time) {
				dist[cur.end] = dist[cur.start] + cur.time;
			}
		}
	}

	bool cycle = false;
	// 간선리스트 1번 더 순회
	for (auto cur : bus) {
		// 시작점의 dist가 INF면 아직 갈 수 없음
		if (dist[cur.start] == INF) continue;
		// dist가 갱신되면 음수 사이클 존재
		if (dist[cur.end] > dist[cur.start] + cur.time) {
			cycle = true;
			break;
		}
	}

	// 음수사이클이 있으면 -1 출력
	if (cycle) printf("-1\n");
	else { // 1에서 출발해 2 ~ n까지 가는 경로 출력
		for (int i = 2; i <= n; i++) {
			// 경로가 없으면 -1 출력
			if (dist[i] == INF) printf("-1\n");
			else printf("%lld\n", dist[i]);
		}
	}
	return 0;
}
