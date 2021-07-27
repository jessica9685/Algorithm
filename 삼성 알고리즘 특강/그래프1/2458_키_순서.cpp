// 2458_키_순서.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 500 + 1
#define INF 999999999

int n, m; 

// 키가 몇 번째인지 알려면 모든 경로를 알아야 함
// -> 플로이드 - 워셜
int main() {
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
		int a, b;
		scanf("%d %d", &a, &b);
		dist[a][b] = 1; // a < b를 1로 표시
	}


	// 플로이드-워셜
	// k - i - j (k는 경유지, i는 출발, j는 도착)
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	int ans = 0; // 자신의 키 순서를 알 수 있는 학생 수
	for (int i = 1; i <= n; i++) {
		bool know = true; 
		for (int j = 1; j <= n; j++) {
			// dist[i][j] 또는 dist[j][i]를 알아야 키 순서 알 수 있음
			if (dist[i][j] == INF && dist[j][i] == INF) {
				know = false;
				break;
			}
		}
		if (know) ans++;
	}

	printf("%d\n", ans);
	return 0;
}
