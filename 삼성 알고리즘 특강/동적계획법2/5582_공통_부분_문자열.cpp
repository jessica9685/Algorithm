// 5582_공통_부분_문자열.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[4001][4001];
// dp[i][j] : s1[i]와 s2[j]가 일치할 때 일치하는 문자열의 길이
// s1[i]와 s2[j]가 포함된 공통 부분 문자열의 길이

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s1 >> s2;

	int result = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				result = max(dp[i][j], result);
			}
		}
	}

	printf("%d\n", result);
	return 0;
}
