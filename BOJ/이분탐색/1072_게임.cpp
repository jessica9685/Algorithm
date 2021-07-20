// 1072_게임.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
/*
	추가로 할 수 있는 게임 횟수의 최대값
	= 98%를 99%로 올리기 위해 필요한 게임 횟수
	= x
	(ex. x = 50, y = 49 -> 98%
		(x + y) / (x + x) * 100 = 99%)
*/

typedef long long ll;

ll x, y;
int z;

int main() {
	scanf("%lld %lld", &x, &y);
	z = (y * 100) / x;

	if (z >= 99) {
		printf("-1\n");
		return 0;
	}

	ll left = 0;
	ll right = x;
	ll result = 0;
	int rate = z;

	while (left <= right) {
		ll mid = (left + right) / 2;

		ll total = x + mid;
		ll win = y + mid;

		rate = (win * 100) / total;

		if (rate <= z) { // 승률이 오르지 않았으면
			result = mid + 1;
			left = mid + 1;
		}
		else { // 승률이 오르면
			right = mid - 1;
		}
	}

	if (result > x) result = -1;
	printf("%lld\n", result);
	return 0;
}
