// 9465_스티커.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n;
int sticker[2][MAX];
int dp[2][MAX]; // dp[r][c]: r행 c열을 선택했을 때 최대값 


int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		scanf("%d", &n);
		for (int r = 0; r < 2; r++) {
			for (int c = 0; c < n; c++) {
				scanf("%d", &sticker[r][c]);
			}
		}

		// 시작점: 0행 0열 or 1행 0열
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[0][1] + sticker[1][0];
		dp[1][1] = sticker[1][1] + sticker[0][0];

		for (int i = 2; i < n; i++) {
			dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		int ans = max(dp[0][n - 1], dp[1][n - 1]);
		printf("%d\n", ans);
	}
	return 0;
}
