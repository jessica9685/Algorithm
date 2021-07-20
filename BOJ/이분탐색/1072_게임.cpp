// 1072_게임.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000

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
	ll right = MAX;
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

	if (result > MAX) result = -1;
	printf("%lld\n", result);
	return 0;
}
