// 11062_카드_게임.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> card;
int dp[2][1000][1000];
// dp[근우/명우][카드범위 left][카드범위 right] = 근우가 얻을 수 있는 최대 점수

// 분할 정복 (근우: 0, 명우: 1)
int cardGame(int left, int right, int flag) {
	// 마지막 카드이면
	if (left == right) {
		if (flag == 0) { // 근우
			return dp[0][left][right] = card[left];
		}
		else { // 명우
			return dp[1][left][right] = 0;
		}
	}
	// 이미 갱신되었으면
	if (dp[flag][left][right] != 0) {
		return dp[flag][left][right];
	}
	// 분할정복
	// 근우
	if (flag == 0) {
		dp[flag][left][right] = max(cardGame(left, right - 1, 1) + card[right],
									cardGame(left + 1, right, 1) + card[left]);
	}
	// 명우
	else {
		dp[flag][left][right] = min(cardGame(left, right - 1, 0), 
									cardGame(left + 1, right, 0));
	}

	return dp[flag][left][right];
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		card.resize(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &card[i]);
		}

		memset(dp, 0, sizeof(dp)); // dp 초기화
		int result = cardGame(0, n - 1, 0);
		printf("%d\n", result);
	}

	return 0;
}
