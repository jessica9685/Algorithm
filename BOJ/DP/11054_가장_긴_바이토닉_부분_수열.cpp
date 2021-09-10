// 11054_가장_긴_바이토닉_부분_수열.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int dp[1001][2]; // i까지의 증가(0)/감소(1)하는 수열 길이

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr.push_back(num);
	}

	/* 0 ~ n까지 증가하는 수열 dp에 저장 */
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		int tmp = 1;
		int maxLen = 1; // 증가하는 최대 수열 길이
		bool isAsc = false; // i를 포함한 증가하는 수열이 존재하면 true

		// arr[0] ~ arr[i]까지 탐색하면서 증가하는 수열 찾기
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				tmp = dp[j][0];
				isAsc = true;
			}
			// 최대 길이 갱신
			if (maxLen < tmp) maxLen = tmp;
		}

		// i까지의 증가하는 수열이 2 이상이면 갱신
		if (isAsc) dp[i][0] = maxLen + 1;
	}

	/* 0 ~ n까지 감소하는 수열 dp에 저장 */
	for (int i = n - 1; i >= 0; i--) {
		dp[i][1] = 1;
		int tmp = 1;
		int maxLen = 1; // 증가하는 최대 수열 길이
		bool isAsc = false; // i를 포함한 증가하는 수열이 존재하면 true

		// arr[0] ~ arr[i]까지 탐색하면서 증가하는 수열 찾기
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				tmp = dp[j][1];
				isAsc = true;
			}
			// 최대 길이 갱신
			if (maxLen < tmp) maxLen = tmp;
		}

		// i까지의 증가하는 수열이 2 이상이면 갱신
		if (isAsc) dp[i][1] = maxLen + 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp = dp[i][0] + dp[i][1] - 1;
		if (ans < tmp) ans = tmp;
	}

	printf("%d\n", ans);
	return 0;
}
