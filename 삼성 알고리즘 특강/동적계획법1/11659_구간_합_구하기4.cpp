// 11659_구간_합_구하기4.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000 + 1

int n, m;
int num[MAX];
int dp[MAX] = { 0, };

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		dp[i] = dp[i - 1] + num[i]; // 누적합
	}

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int result = dp[b] - dp[a - 1];
		printf("%d\n", result);
	}
	return 0;
}
