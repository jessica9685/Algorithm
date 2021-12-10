// 1719_택배.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 201
#define INF 987654321

int graph[MAX][MAX]; // a->b로 갈때 처음 들러야하는 곳

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	// dist 배열 초기화
	int dist[MAX][MAX];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c;
		dist[b][a] = c;

		graph[a][b] = b;
		graph[b][a] = a;
	}

	// 플로이드-와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					graph[i][j] = graph[i][k];
				}
			}
		}
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 0) printf("- ");
			else printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
