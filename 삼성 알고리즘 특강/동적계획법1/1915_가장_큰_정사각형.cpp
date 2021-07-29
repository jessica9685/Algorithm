// 1915_가장_큰_정사각형.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
int square[1001][1001];
int dp[1001][1001]; 
// dp[i][j]: (i, j)가 우측 하단인 큰 정사각형의 한 변의 길이

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &square[i][j]);
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (square[i][j] == 1) {
				if (dp[i][j - 1] == 0 || dp[i - 1][j] == 0 || dp[i - 1][j - 1] == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1;
				}
				result = max(result, dp[i][j]);
			}
		}
	}

	printf("%d\n", result * result);
	return 0;
}
