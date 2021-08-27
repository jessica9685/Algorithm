// 4375_1.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	// 입력은 EOF가 나올 때까지 계속 받음
	while (scanf("%d", &n) != EOF) {
		int ans = 1; // 자리수
		int num = 1; // 1로만 이루어진 숫자

		// 1로만 이루어진 n의 배수 찾기
		while (true) {
			// num이 n의 배수가 맞으면 자리수 출력
			if (num % n == 0) {
				printf("%d\n", ans);
				break;
			}
			// n의 배수가 아니면
			else {
				// num이 매우 크므로 모듈러 연산한 값을 사용
				num = (num * 10) % n + 1;
				ans++;
			}
		}
	}

	return 0;
}
