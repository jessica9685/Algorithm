// 2579_계단_오르기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 300 + 1

int n; // 계단 개수
int score[MAX];
int dp[MAX]; // 해당 계단까지의 최대 점수

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &score[i]);
	}

	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	for (int i = 3; i <= n; i++) {
		// 1칸 전에 밟았을 때 (O X O O)
		// dp[n - 3] + score[n - 1] + score[n]
		int beforeOne = dp[i - 3] + score[i - 1];
		// 2칸 전에 밟았을 때 (O X O)
		// dp[n - 2] + score[n]
		int beforeTwo = dp[i - 2];
		dp[i] = max(beforeOne, beforeTwo) + score[i];
	}

	printf("%d\n", dp[n]);

	return 0;
}
