// 9252_LCS2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1001][1001];
// dp[i][j] : s1의 [0, i]와 s2의 [0, j] 문자 중 서로 같은 문자의 개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s1 >> s2;

	int n = s1.size();
	int m = s2.size();

	// 문자열 길이 구하기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 두 문자가 서로 같을 경우
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			// 두 문자가 다를 경우
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int result = dp[n][m];
	printf("%d\n", result);

	// 문자열 구하기
	// 맨 뒤부터 거꾸로 탐색
	stack<int> ans;
	if (result != 0) {
		while (n != 0 && m != 0) {
			// 문자가 같으면
			if (s1[n - 1] == s2[m - 1]) {
				ans.push(s1[n - 1]);
				n--; m--;
			}
			// 문자가 다를 경우 -> dp가 같은 방향으로 이동하기
			else if (dp[n][m] == dp[n - 1][m]) n--;
			else if (dp[n][m] == dp[n][m - 1]) m--;
		}
	}

	// 문자열 출력
	while (!ans.empty()) {
		printf("%c", ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}
