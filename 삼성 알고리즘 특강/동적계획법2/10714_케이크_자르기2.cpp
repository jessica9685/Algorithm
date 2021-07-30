// 10714_케이크_자르기2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> cake;
ll dp[2][2000][2000]; // dp[flag][left][right]
// flag: 0 = JOI, 1 = IOI
// left: 왼쪽에서 먹은 케이크, right: 오른쪽에서 먹은 케이크

// 오른쪽 조각 먹을 때
int goRight(int cur) {
	if (cur == 0) return n - 1;
	else return cur - 1;
}

// 왼쪽 조각 먹을 때
int goLeft(int cur) {
	return (cur + 1) % n;
}

// 분할 정복
ll eatcake(int flag, int left, int right) {
	// 모든 케익을 다 먹으면
	if (goRight(right) == left) {
		if (flag == 0) { // joi
			return dp[0][left][right] = 0;
		}
		else { // ioi
			return dp[1][left][right] = 0;
		}
	}
	// 이미 계산된 dp면 넘어감
	if (dp[flag][left][right] != -1) return dp[flag][left][right];

	// 분할정복 (왼쪽/오른쪽 케이크 먹을 때 최대값)
	if (flag == 0) { // joj -> 자유롭게 먹을 수 있음
		ll leftCake = cake[goLeft(left)] + eatcake(1, goLeft(left), right);
		ll rightCake = cake[goRight(right)] + eatcake(1, left, goRight(right));

		return dp[flag][left][right] = max(leftCake, rightCake);
	}
	else { // ioi -> 왼쪽/오른쪽 중 더 큰 케이크 먹음
		ll leftCake = cake[goLeft(left)];
		ll rightCake = cake[goRight(right)];

		if (leftCake > rightCake) { // 왼쪽이 더 크면
			return dp[flag][left][right] = eatcake(0, goLeft(left), right);
		}
		else return dp[flag][left][right] = eatcake(0, left, goRight(right));
	}

}

int main() {
	scanf("%d", &n);
	cake.resize(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &cake[i]);
	}

	memset(dp, -1, sizeof(dp));
	ll result = 0;
	// 가장 먼저 몇번째 조각을 먹었는지에 따라 결과값 달라짐
	for (int i = 0; i < n; i++) {
		result = max(result, cake[i] + eatcake(1, i, i));
	}

	printf("%lld\n", result);
	return 0;
}
