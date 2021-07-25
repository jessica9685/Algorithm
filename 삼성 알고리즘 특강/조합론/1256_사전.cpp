// 1256_사전.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n; // a의 개수
int m; // z의 개수
int k; // k번째 문자열
string answer;

// N + M <= 200
int dp[201][201];
int combination(int n, int r) {
	if (n == r || r == 0) return 1;
	else if (dp[n][r] != 0) { // nCr
		return dp[n][r];
	}
	else {
		// 결과값이 범위를 벗어나는 경우 최대값으로 치환
		return dp[n][r] = min((int)1e9, combination(n - 1, r - 1) + combination(n - 1, r));
	}
}

void query(int n, int m, int k, string str) {
	if (n + m == 0) {
		answer = str;
		return;
	}

	// a를 다 쓴 경우
	else if (n == 0) {
		str.push_back('z');
		query(n, m - 1, k, str);
	}
	// z를 다 쓴 경우
	else if (m == 0) {
		str.push_back('a');
		query(n - 1, m, k, str);
	}
	else {
		// z를 기준으로
		int leftCount = combination(n + m - 1, m);
		if (k <= leftCount) {
			str.push_back('a');
			query(n - 1, m, k, str);
		}
		else { 
			str.push_back('z');
			query(n, m - 1, k - leftCount, str);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;

	// 사전에 있는 문자열의 개수가 k보다 작으면
	if (k > combination(n + m, m)) {
		cout << -1 << "\n";
	}
	else {
		query(n, m, k, "");
		cout << answer << "\n";
	}

	return 0;
}
