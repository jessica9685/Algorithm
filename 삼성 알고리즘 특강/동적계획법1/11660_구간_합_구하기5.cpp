// 11660_구간_합_구하기5.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1024 + 1

int n, m;
int graph[MAX][MAX];
int dp[MAX][MAX] = { 0, }; // (1, 1)부터 (x, y)까지의 누적합

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
			dp[i][j] += graph[i][j];
		}
	}

	while (m--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		if (x1 == x2 && y1 == y2) printf("%d\n", graph[x1][y1]);
		else {
			int sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
			printf("%d\n", sum);
		}
	}

	return 0;
}
