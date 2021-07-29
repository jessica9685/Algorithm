// 5626_제단.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;
int height[10000];
int dp[10000][5001];
// dp[i][j] i열의 높이가 j일 때 가능한 최대 경우의 수
// i열의 최대 높이 = min(i, (N - 1) - i)
// j 최대 = N/2

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &height[i]);

		// 입력받은 높이가 가능한 최대치를 벗어난 경우 -> 불가능
		if (height[i] > min(i, (N - 1) - i)) {
			printf("0\n");
			return 0;
		}
	}

	// 양 끝은 무조건 0
	dp[0][0] = 1;
	for (int i = 1; i < N; i++) {
		// 높이를 모르는 경우
		if (height[i] == -1) {
			int maxHeight = min(i, (N - 1) - i);
			// i열에서 가능한 높이 일일이 경우의 수 구함
			for (int j = 0; j <= maxHeight; j++) {
				// 가능한 높이차 = -1, 0, 1;
				for (int k = -1; k <= 1; k++) {
					int preHeight = j + k;
					if (preHeight < 0) continue;
					dp[i][j] += dp[i - 1][preHeight];
					dp[i][j] %= 1000000007;
				}
			}
		}
		// 높이를 아는 경우
		else {
			// 가능한 높이차 = -1, 0, 1;
			for (int k = -1; k <= 1; k++) {
				int preHeight = height[i] + k;
				if (preHeight < 0) continue;
				dp[i][height[i]] += dp[i - 1][preHeight];
				dp[i][height[i]] %= 1000000007;
			}
		}
	}
	
	printf("%d\n", dp[N - 1][0] % 1000000007);

	return 0;
}
