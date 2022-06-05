// 1912_연속합.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n;
int seq[MAX];
int dp[MAX]; // seq[i]를 시작으로 했을 때 최대합

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	dp[n - 1] = seq[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		dp[i] = max(dp[i + 1] + seq[i], seq[i]);
	}

	int ans = -1001; // 최대값은 음수일 수 있음
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
