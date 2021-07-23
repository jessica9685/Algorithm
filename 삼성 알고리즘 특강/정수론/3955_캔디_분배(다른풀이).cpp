// 3955_캔디_분배.cpp
// 확장 유클리드 호제법
// 참고: https://j1w2k3.tistory.com/m/1338
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct ExtendedGcdResult {
	ll s;
	ll t;
	ll r;
};

ll A; // 인원수
ll B; // 1봉지당 사탕 개수
ll x; // 1인당 나눠줄 사탕 개수
ll y; // 구매할 사탕봉지 개수

// Ax + 1 = By -> Ax + By = 1의 형태로 변환
// -Ax + By = 1 -> A의 부호를 양수로 변환
// A(-x) + By = 1 
// k(-x) + cy = 1

ExtendedGcdResult extendedGcd(ll a, ll b) {
	// -x, y의 해를 구함
	ll s0 = 1, t0 = 0, r0 = a;
	ll s1 = 0, t1 = 1, r1 = b;

	ll temp;
	while (r1 != 0) {
		ll q = r0 / r1;

		temp = r0 - r1 * q;
		r0 = r1;
		r1 = temp;

		temp = s0 - s1 * q;
		s0 = s1;
		s1 = temp;

		temp = t0 - t1 * q;
		t0 = t1;
		t1 = temp;
	}

	ExtendedGcdResult result = { s0, t0, r0 };
	return result;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld %lld", &A, &B);

		ExtendedGcdResult result = extendedGcd(A, B);

		// d = gcd(A, B) = r
		// Ax + By = c일 때, c % d == 0이어야 해를 가질 수 있음
		if (result.r != 1) printf("IMPOSSIBLE\n");
		else {
			// x0 = s * (c/d)
			// y0 = t * (c/d)
			ll x0 = result.s;
			ll y0 = result.t;

			// x = x0 + (B/d) * k
			// y = y0 - (A/d) * k

			// x < 0
			// x0 + B * k < 0
			// k < -x0 / B
			// 0 < y <= 1e9
			// 0 < y0 - A * k <= 1e9
			// -y0 < -A * k <= 1e9 - y0

			// (y0 - 1e9) / A <= k < y0 / A
			// 					 k < -x0 / B
			ll kFromY = (ll)ceil((double)y0 / (double)A) - 1;
			ll kFromX = (ll)ceil((double)(-x0) / (double)B) - 1;
			ll k = min(kFromX, kFromY);
			y = y0 - A * k;
			if (y <= 1e9) printf("%lld\n", y);
			else printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
