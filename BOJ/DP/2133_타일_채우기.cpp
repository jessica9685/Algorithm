// 2133_타일_채우기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	// n이 홀수이면 경우의 수 0
	if (n % 2 == 1) {
		printf("0\n");
		return 0;
	}

	int dp[31] = { 0, }; // 3xi 크기의 벽을 채우는 경우의 수
	// 초기값
	dp[0] = 1;
	dp[2] = 3;

	// 각 단계마다 해당 단계에서만 나타날 수 있는 특이 케이스가 2개 존재
	/* ex. 
		n = 6일 때 
			1) dp[4] * dp[2] (= dp[4] * 3) // 좌측만 고려했을 때 
			2) 2 * dp[2] // 우측 특이 케이스
			3) 2 // n = 6일 때 나올 수 있는 특이케이스

		n = 8일 때
			1) dp[6] * dp[2]
			2) 2 * (dp[4] + dp[2]) // 우측 특이 케이스
			3) 2 // n = 8일 때 나올 수 있는 특이 케이스
	*/
	// 점화식: dp[n] = (dp[n - 2] * dp[2]) + 2 * sum(dp[n - i]) + 2
	for (int i = 4; i <= n; i += 2) {
		dp[i] += dp[i - 2] * 3; // 1) 좌측만 고려
		for (int j = 4; j < i; j += 2) { // 2) 우측 특이케이스 고려
			dp[i] += dp[i - j] * 2;
		}
		dp[i] += 2; // 3) 특이케이스
	}

	printf("%d\n", dp[n]);
	return 0;
}
