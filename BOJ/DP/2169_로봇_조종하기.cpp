// 2169_로봇_조종하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int n, m;
int mars[MAX][MAX];
int dp[MAX][MAX]; // (i, j)까지 탐사했을 때 최대 가치
int toLeft[MAX];
int toRight[MAX];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) scanf("%d", &mars[i][j]);
	}

	// 1행은 무조건 1가지 경우밖에 안나옴
	dp[1][1] = mars[1][1];
	for (int j = 2; j <= m; j++) {
		dp[1][j] = dp[1][j - 1] + mars[1][j];
	}

	// 2행부터 탐색
	for (int i = 2; i <= n; i++) {
		// 오른쪽 (i행 1열 -> i행 m열)
		toRight[1] = dp[i - 1][1] + mars[i][1];
		for (int j = 2; j <= m; j++) {
			toRight[j] = max(toRight[j - 1], dp[i - 1][j]) + mars[i][j];
		}

		// 왼쪽 (i행 m열 -> i행 1열)
		toLeft[m] = dp[i - 1][m] + mars[i][m];
		for (int j = m - 1; j >= 1; j--) {
			toLeft[j] = max(toLeft[j + 1], dp[i - 1][j]) + mars[i][j];
		}

		// 둘 중 더 큰 값 저장
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(toLeft[j], toRight[j]);
		}
	}

	printf("%d\n", dp[n][m]);
	return 0;
}
