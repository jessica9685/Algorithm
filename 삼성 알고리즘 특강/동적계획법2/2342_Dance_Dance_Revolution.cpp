// 2342_Dance_Dance_Revolution.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> command;
int n; // 명령 횟수
int dp[100000][5][5]; // dp[step 횟수][왼발 방향][오른발 방향] = i번째 스탭일 때 최소 힘

// 발 이동에 따른 cost
int cost(int from, int to) {
	if (from == to) return 1;
	else if (from == 0) return 2;
	else if (abs(from - to) == 2) return 4;
	else return 3;
}

// 분할 정복
int ddr(int left, int right, int step) {
	// 마지막 명령이 끝나면 0 리턴
	if (step == n) {
		return 0;
	}
	// 이미 계산된 dp면 넘어감
	if (dp[step][left][right] != 0) return dp[step][left][right];

	// 분할정복 (왼발/오른발로 갔을 때의 비용 최소값)
	int leftCost = cost(left, command[step])
		+ ddr(command[step], right, step + 1);
	int rightCost = cost(right, command[step])
		+ ddr(left, command[step], step + 1);

	dp[step][left][right] = min(leftCost, rightCost);
	return dp[step][left][right];
}

int main() {
	while (true) {
		int c;
		scanf("%d", &c);
		if (c == 0) break;
		else {
			command.push_back(c);
		}
	}

	n = command.size();
	memset(dp, 0, sizeof(dp));

	int result = ddr(0, 0, 0);
	printf("%d\n", result);
}
