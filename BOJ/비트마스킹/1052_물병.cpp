// 1052_물병.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
	scanf("%d %d", &N, &K);

	if (K >= N) printf("0\n");
	else {
		int answer = 0; // 구매해야하는 물병 수

		while (true) {
			int cnt = 0; // 합치고 남은 물병 수
			int n = N;
			while (n > 0) {
				// 2로 나눠지지 않으면 물병 추가
				if (n % 2 == 1) cnt++;
				n /= 2;
			}

			// 물병을 k개 이하로 만들면 종료
			if (K >= cnt) break;

			// 조건을 만족하지 않으면 물병 구매
			N++;
			answer++;
		}

		printf("%d\n", answer);
	}
	return 0;
}
