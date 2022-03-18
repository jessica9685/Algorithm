// 1509_팰린드롬_분할.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 2500
#define INF 987654321

string str;
int n; // 문자열 길이
// palindrome[a][b]: a번째 ~ b번째 문자로 이루어진 문자열이 팰린드롬이면 true
bool palindrome[MAX][MAX]; 
// dp[a]: a번 문자까지의 팰린드롬 분할 최소 횟수
// 구해야할 답 = dp[n - 1]
int dp[MAX]; 

// start, end: str의 분할 인덱스 
bool is_palindrome(int start, int end) {
	// 1글자면 무조건 팰린드롬
	if (start == end) return true;
	// 2글자 이상일 때
	else {
		int len = end - start + 1;
		for (int i = 0; i < len / 2; i++) {
			if (str[start + i] != str[end - i]) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	n = str.size();

	// 분할 시 팰린드롬인 경우의 수 파악
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// 1글자면 무조건 팰린드롬
			if (i == j) palindrome[i][j] = true;
			// 2글자 이상이면
			else palindrome[i][j] = is_palindrome(i, j);
		}
	}

	// dp
	for (int end = 0; end < n; end++) {
		dp[end] = INF;
		for (int start = 0; start <= end; start++) {
			// start ~ end까지 분할한 문자열이 팰린드롬이면
			if (palindrome[start][end] == true) {
				// start 이전 문자열의 최소 분할 횟수 + 1
				dp[end] = min(dp[end], dp[start - 1] + 1);
			}
		}
	}

	printf("%d\n", dp[n - 1]);
	return 0;
}
