// 2011_암호코드.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000

string str;
long long dp[5001]; // i번째 수까지 읽을 수 있는 문자 개수
int arr[5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;

	// 문자열을 숫자로 변경 (1부터 시작)
	int len = str.size();
	for (int i = 1; i <= len; i++) {
		arr[i] = str[i - 1] - '0';
	}

	// 0은 잘못된 암호
	if (arr[1] == 0) cout << "0\n";
	else {
		dp[0] = 1;
		for (int i = 1; i <= len; i++) {
			// 1 ~ 9로 인식하면
			if (arr[i] >= 1 && arr[i] <= 9) {
				dp[i] += dp[i - 1];
				dp[i] %= MOD;
			}
			// 10 ~ 26으로 인식하면
			int tmp = arr[i] + arr[i - 1] * 10;
			if (tmp >= 10 && tmp <= 26) {
				dp[i] += dp[i - 2];
				dp[i] %= MOD;
			}
		}
		cout << dp[len] << "\n";
	}
	return 0;
}
