// 1932_정수_삼각형.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
int triangle[501][501] = { 0, };
int dp[501][501] = { 0, };

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}
	
	dp[1][1] = triangle[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = dp[i - 1][j];
			}
			else if (j == n) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
			dp[i][j] += triangle[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(dp[n][i], ans);
	}

	printf("%d\n", ans);
	return 0;
}
