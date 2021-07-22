// 3955_캔디_분배.cpp
// 확장 유클리드 호제법
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, c; // k : 인원수, c : 1봉지당 사탕 개수
ll x, y; // x : 1인당 사탕 개수, y : 봉지 개수

// kx + 1 = cy
// -kx + cy = 1;
ll euclid(ll a, ll b) {
	ll s1 = 1, t1 = 0, r1 = a;
	ll s2 = 0, t2 = 1, r2 = b;
	while (r2 != 0) {
		ll q = r1 / r2;

		ll r = r1 - r2 * q;
		r1 = r2;
		r2 = r;

		ll s = s1 - s2 * q;
		s1 = s2;
		s2 = s;

		ll t = t1 - t2 * q;
		t1 = t2;
		t2 = t;
	}

	// 해가 없을 경우
	if (abs(r1) != 1) return -1;
	// 해가 있는 경우
	else {
		// (-k)x + cy = 1이 되는 (x, y) == (s1, t1)
		// x = s + cn, y = t + kn => (-ks -kcn + ct + kcn = 1)
		x = s1 / r1, y = t1 / r1;
		while (y < 1 || x < 1) { // 해가 자연수가 될 때까지 증가
			x += b;
			y += -a;
			if (y > 1e9) break;
		}
		if (y > 1e9) return -1;
		else return y;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld %lld", &k, &c);
		
		/* 주의 : c = 1, k = 1일 경우 y = 2 */
		// if문의 순서가 바뀌면 k == 1 조건문 안에 c == 1일 때의 처리가 따로 필요
		if (c == 1) { // 1봉지당 사탕 개수가 1일 때
			y = k + 1;
			if (y > 1e9) printf("IMPOSSIBLE\n");
			else printf("%lld\n", y);
			continue;
		}
		else if (k == 1) { // 인원수가 1명일 때
			printf("1\n"); // 사탕봉지 1개 필요
			continue;
		}
		else {
			ll answer = euclid(-k, c);
			if (answer == -1) printf("IMPOSSIBLE\n");
			else printf("%lld\n", answer);
		}
	}
	return 0;
}
