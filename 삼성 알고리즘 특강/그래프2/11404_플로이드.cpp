// 11404_플로이드.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100 + 1
#define INF 99999999

typedef struct edge {
	int next;
	int cost;
};

int n; // 도시 개수
int m; // 버스 개수

int main() {
	scanf("%d", &n);
	scanf("%d", &m);

	// dist 배열 초기화
	int dist[MAX][MAX];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			dist[i][j] = INF;
		}
	}

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		// 같은 노선의 버스가 여러개 -> 최소 비용만 저장
		dist[a][b] = min(dist[a][b], c);
	}

	// 플로이드 - 와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	
	// i -> j로 가는 최소 비용 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF || i == j) dist[i][j] = 0;
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}
