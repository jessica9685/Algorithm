// 1256_사전.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000

// N: a 개수, M: z 개수
int N, M, K;
// nCr
// N + M <= 200
int dp[201][201]; 
string ans;

// nCr 계산 결과 리턴
int combi(int n, int r) {
	if (n == r || r == 0) return 1;
	else if (dp[n][r] != 0) return dp[n][r];
	else {
		dp[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
		// K의 최대값을 넘어서면 MAX로 갱신
		if (dp[n][r] > MAX) dp[n][r] = MAX;
		return dp[n][r];
	}
}

// 조건을 만족하는 문자열 찾기
void dfs(int n, int m, int k, string str) {
	if (n + m == 0) {
		ans = str;
		return;
	}

	// a를 다 쓴 경우
	if (n == 0) dfs(n, m - 1, k, str + 'z');
	// z를 다 쓴 경우
	else if (m == 0) dfs(n - 1, m, k, str + 'a');
	else {
		// a: (n - 1)개, z: m개일 때 문자열 개수
		int cnt = combi(n + m - 1, m);
		// 더 앞부분일 때 -> a 추가
		if (k <= cnt) dfs(n - 1, m, k, str + 'a');
		// 뒷부분일 때 -> z 추가
		else dfs(n, m - 1, k - cnt, str + 'z');
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	if (K > combi(N + M, N)) printf("-1\n");
	else {
		dfs(N, M, K, "");
		cout << ans << "\n";
	}
	return 0;
}
