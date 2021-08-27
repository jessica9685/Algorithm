// 1520_내리막_길.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int M, N;
int MAP[MAX][MAX];

// (y, x)에서 (N - 1, M - 1)까지 가는 경우의 수
int dp[MAX][MAX];;
int ans;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dfs(int y, int x) {
	// 도착점일 때 -> 경우의 수 1
	if (y == N - 1 && x == M - 1) return 1;
	// 이미 방문했으면
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0; // 방문 표시
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		// 높이가 더 낮은 지점만 방문
		if (MAP[ny][nx] < MAP[y][x]) {
			dp[y][x] += dfs(ny, nx);
		}
	}

	return dp[y][x];
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &MAP[i][j]);
			dp[i][j] = -1;
		}
	}

	ans = dfs(0, 0);

	printf("%d\n", ans);
	return 0;
}
