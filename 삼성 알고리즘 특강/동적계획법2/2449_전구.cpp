// 2449_전구.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, K;
int light[200];
int dp[200][200];
// dp[i][j] : i번째 ~ j번째 전구의 색상이 모두 같아질 때 최소 비용

int divideConquer(int start, int end) {
	// 자기 자신이면 0
	if (start == end) return 0;

	// 이미 dp를 알고 있으면 리턴
	if (dp[start][end] != 0) return dp[start][end];

	// 분할해 확인
	int ret = INT_MAX;
	for (int i = start; i < end; i++) {
		int left = divideConquer(start, i);
		int right = divideConquer(i + 1, end);

		// left, right 양쪽 구간의 색이 같은 경우
		if (light[start] == light[i + 1]) {
			ret = min(ret, left + right);
		}
		// 양쪽 구간의 색이 다를 경우
		else {
			ret = min(ret, left + right + 1);
		}
	}
	return dp[start][end] = ret;
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &light[i]);
	}

	dp[0][N - 1] = divideConquer(0, N - 1);

	printf("%d\n", dp[0][N - 1]);
	return 0;
}
