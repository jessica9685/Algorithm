// 11066_파일_합치기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 501
#define INF 987654321

int T;
int n; // 장 수
int files[MAX]; // 각 파일의 비용
int dp[MAX][MAX]; // dp[a][b]: a ~ b 구간까지의 최소 비용
int sum[MAX]; // sum[a]: 1 ~ a번째까지 합

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &files[i]);
			sum[i] = sum[i - 1] + files[i];
		}

		for (int i = 1; i <= n; i++) { // 범위의 크기
			for (int j = 1; j <= n - i; j++) { // 범위 시작 부분
				dp[j][j + i] = INF; // 초기값
				
				/*
					dp[4][11]의 최소값
					= dp[4][5] + dp[6][11] + (sum[11] - sum[3])
					= dp[j][k] + dp[k + 1][j + i] + (sum[j + i] - sum[j - 1])
				*/
				for (int k = j; k < i + j; k++) {
					dp[j][j + i] = min(dp[j][j + i],
						dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
				}
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}
