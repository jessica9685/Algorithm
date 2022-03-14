// 1937_욕심쟁이_판다.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int n;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int forest[MAX][MAX];
int dp[MAX][MAX]; // dp[a][b]: (a, b)에서 시작했을 때 최대 방문 칸수

int dfs(int y, int x) {
	// dp값이 이미 존재하면 리턴
	if (dp[y][x] != 0) return dp[y][x];
	dp[y][x] = 1; // 초기화

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 범위 벗어나면 패스
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		// 다음 칸 이동
		if (forest[ny][nx] > forest[y][x]) {
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
