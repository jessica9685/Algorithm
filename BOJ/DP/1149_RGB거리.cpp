// 1149_RGB거리.cpp
using namespace std;
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>;
#define MAX 3000000

int n;
int cost[1000][3]; // 순서대로 R, G, B의 비용
int dp[1000][3];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	// dp 초기화
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int i = 0; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
	}

	int result = MAX;
	for (int i = 0; i < 3; i++) {
		if (dp[n - 1][i] < result) result = dp[n - 1][i];
	}

	printf("%d\n", result);

	return 0;
}
