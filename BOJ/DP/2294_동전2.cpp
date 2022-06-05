// 2294_동전2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int n, k;
int coin[100];
int dp[MAX]; // i원을 만드는데 필요한 동전의 최소 개수

int main() {
	scanf("%d %d", &n, &k);

	// dp 초기화
	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	int ans = 0;
	if (dp[k] == 10001) ans = -1;
	else ans = dp[k];
	
	printf("%d\n", ans);
	return 0;
}
