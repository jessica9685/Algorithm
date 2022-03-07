// 2225_합분해.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 201

int n, k;
int dp[MAX][MAX] = { 0, }; // dp[n][k]

int main() {
	scanf("%d %d", &n, &k);

	// dp[n][1] = 1
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			// dp[1][k] = k
			for (int j = 1; j <= k; j++) {
				dp[i][j] = j;
			}
		}
		dp[i][1] = 1;
	}

	// 점화식
	// dp[n][k] = dp[n - 1][k] + dp[n][k - 1]
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	printf("%d\n", dp[n][k]);
	return 0;
}
