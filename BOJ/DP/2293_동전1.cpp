// 2293_동전1.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> coin(n + 1, 0);
	for (int i = 1; i <= n; i++) scanf("%d", &coin[i]);

	sort(coin.begin(), coin.end()); // 오름차순
	vector<int> dp(k + 1, 0); // i원을 만들 수 있는 경우의 수
	
	// 0원을 만들 수 있는 경우의 수 = 1
	dp[0] = 1;

	for (int i = 1; i <= n; i++) { // 동전 i에 대해서
		// i원부터 k원까지 만들 수 있는 경우의 수
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d\n", dp[k]);
	return 0;
}
