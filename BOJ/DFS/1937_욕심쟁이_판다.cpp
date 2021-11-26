// 1937_욕심쟁이_판다.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int n;
int forest[MAX][MAX];
int dp[MAX][MAX]; // (a, b)에서 시작했을 때 갈 수 있는 최대 칸 수
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int dfs(int y, int x) {
	// dp값이 이미 계산되어 있으면 리턴
	if (dp[y][x] != 0) return dp[y][x];

	dp[y][x] = 1; // 초기화
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (forest[ny][nx] > forest[y][x]) {
			// 최대값 갱신
			dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
		}
	}

	return dp[y][x];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &forest[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dfs(i, j));
		}
	}

	printf("%d\n", ans);
	return 0;
}
