// 16953_A→B.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;

int main() {
	scanf("%lld %lld", &a, &b);

	int cnt = 0;
	while (true) {
		// b를 a로 만들 수 있으면
		if (b == a) { 
			cnt++;
			break;
		}
		// b를 a로 만들 수 없으면
		else if (b < a) {
			cnt = -1;
			break;
		}

		// 1. 1을 추가하는 연산
		if (b % 10 == 1) {
			b /= 10;
		}
		// 2. 2를 곱하는 연산
		else if (b % 2 == 0) {
			b /= 2;
		}
		// 두 연산 모두 불가능한 경우
		else {
			cnt = -1;
			break;
		}
		cnt++;
	}

	printf("%d\n", cnt);
	return 0;
}
