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
	}
	else{
		ll left = 0;
		ll right = x;
		int rate = z;

		while (left < right) {
			ll mid = (left + right) / 2;

			ll total = x + mid;
			ll win = y + mid;

			rate = (win * 100) / total;

			// 승률이 작아지는 경우는 없기 때문에 rate == z로 해도 무방
			if (rate <= z) { // 승률이 오르지 않았으면
				left = mid + 1;
			}
			else { // 승률이 오르면
				right = mid;
			}
		}
		printf("%lld\n", right);
	}
	return 0;
}
