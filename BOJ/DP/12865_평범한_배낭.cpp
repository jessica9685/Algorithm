// 12865_평범한_배낭.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	int things[101][2]; // weight, value
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &things[i][0], &things[i][1]);
	}

	int dp[101][100001]; // 물건 번호, 무게
	for (int i = 1; i <= n; i++) {
		int weight = things[i][0]; // i번째 물건 무게
		int val = things[i][1]; // i번째 물건 가치
		for (int j = 0; j <= k; j++) {
			if (j >= weight) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + val);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}

	printf("%d\n", dp[n][k]);
}
