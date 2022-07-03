// 5569_출근_경로.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int w, h;
// dp[i][j][d][cnt]
// (i, j)까지 가는 경우의 수
// d: 0이면 동쪽, 1이면 북쪽
// cnt: 0이면 1칸, 1이면 2칸 이상 이동
int dp[101][101][2][2];
int mod = 100000;

int main() {
	scanf("%d %d", &w, &h); 

	// dp 초기화
	// 동쪽
	for (int i = 2; i <= w; i++) dp[i][1][0][0] = 1;
	// 북쪽
	for (int j = 2; j <= h; j++) dp[1][j][1][0] = 1;

	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			// 동쪽으로 1칸 이동한 경우
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % mod;
			// 동쪽으로 2칸 이상 이동한 경우 -> 방향 전환
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			// 북쪽으로 1칸 이동한 경우
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % mod;
			// 북쪽으로 2칸 이상 이동한 경우 -> 방향 전환
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) ans += dp[w][h][i][j];
	}
	printf("%d\n", ans % mod);
	return 0;
}
