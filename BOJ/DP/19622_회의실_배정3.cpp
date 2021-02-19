// 19622_회의실_배정3.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 100001

typedef long long ll;

int main() {
	int n;
	scanf("%d", &n);
	
	vector<pair<pair<ll, ll>, ll>> meeting(n + 1);
	ll dp[MAX][2]; 
	// dp[a][0]: a번째 회의를 진행하지 않았을 때 최대 인원
	// dp[a][1]: a번째 회의를 진행했을 때 최대 인원 

	for (int i = 1; i <= n; i++) {
		cin >> meeting[i].first.first >> meeting[i].first.second >> meeting[i].second;
	}
	
	dp[1][1] = meeting[1].second;
	dp[2][1] = meeting[2].second;
	dp[2][0] = meeting[1].second;

	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + meeting[i].second;
	}

	ll ans = max(dp[n][0], dp[n][1]);
	printf("%lld\n", ans);
}

