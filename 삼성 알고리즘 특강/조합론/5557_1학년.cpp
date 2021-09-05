// 5557_1학년.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int num[100];
ll dp[100][21]; // i까지의 결과가 j인 경우의 수

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	dp[0][num[0]] = 1;

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			// i - 1까지의 계산 결과가 j인 경우가 존재할 때
			if (dp[i - 1][j] > 0) {
				// j + (i번째 수)가 20 이하인 경우
				if (j + num[i] <= 20) {
					dp[i][j + num[i]] += dp[i - 1][j];
				}
				// j - (i번째 수)가 0 이상인 경우
				if (j - num[i] >= 0) {
					dp[i][j - num[i]] += dp[i - 1][j];
				}
			}
		}
	}

	printf("%lld\n", dp[n - 2][num[n - 1]]);
	return 0;
}
