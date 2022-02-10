// 11404_플로이드.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define INF 987654321

int dist[MAX][MAX];
int n, m;

int main() {
	scanf("%d", &n); // 도시 개수
	scanf("%d", &m); // 버스 개수

	// dist 배열 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 시작점과 도착점이 같은 경우는 없음
			if (i == j) dist[i][j] = 0; 
			else dist[i][j] = INF;
		}
	}

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		// 같은 노선이 여러 개일 수 있음
		dist[a][b] = min(dist[a][b], c);
	}

	// 플로이드-와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// 경유지 k를 거쳐 가는 최단 거리가 존재하면 갱신
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// 정답 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) printf("0 ");
			else if (dist[i][j] == INF) printf("0 ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
