// 1654_랜선_자르기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

// 랜선 길이의 범위가 2^31 - 1
// left = 1, right = 2^31 - 1이면 mid 범위가 int를 넘어섬
typedef long long ll;

int n, k;
ll len[10001];

int main() {
	scanf("%d %d", &k, &n);

	ll left = 1; // 길이는 1 이상
	ll right = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &len[i]);
		if (right < len[i]) right = len[i];
	}

	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;

		ll cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (len[i] / mid);
		}

		// n개 이상이면
		if (cnt >= n) {
			// left 갱신
			left = mid + 1;
			ans = max(ans, mid);
		}
		// n개 미만이면 right 갱신
		else right = mid - 1;
	}

	printf("%lld\n", ans);
	return 0;
}
