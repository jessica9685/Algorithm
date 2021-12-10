// 1956_운동.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 401
#define INF 987654321

int v, e;

int main() {
	scanf("%d %d", &v, &e);

	// dist 배열 초기화
	int dist[MAX][MAX];
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			dist[i][j] = INF;
		}
	}

	while (e--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c;
	}

	// 플로이드-와샬
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	// 최소 사이클
	int minSum = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (dist[i][j] != INF && dist[j][i] != INF) {
				minSum = min(minSum, dist[i][j] + dist[j][i]);
			}
		}
	}

	if (minSum == INF) printf("-1\n");
	else printf("%d\n", minSum);
	return 0;
}
