// 2660_회장뽑기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51
#define INF 987654321

int n;

int main() {
	scanf("%d", &n);

	// dist 초기화
	int dist[MAX][MAX];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	while (true) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;

		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	// 플로이드-와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// 각 회원의 최대점수 계산
	int member[MAX] = { 0, };
	int minScore = INF;
	for (int i = 1; i <= n; i++) {
		int maxPoint = 0;
		for (int j = 1; j <= n; j++) {
			maxPoint = max(maxPoint, dist[i][j]);
		}
		member[i] = maxPoint;
		minScore = min(minScore, maxPoint);
	}

	// 회장 후보 구하기
	int cnt = 0;
	vector<int> candidate;
	for (int i = 1; i <= n; i++) {
		if (member[i] == minScore) {
			cnt++;
			candidate.push_back(i);
		}
	}

	// 정답 출력
	printf("%d %d\n", minScore, cnt);
	for (auto c : candidate) {
		printf("%d ", c);
	}
	printf("\n");
	return 0;
}
