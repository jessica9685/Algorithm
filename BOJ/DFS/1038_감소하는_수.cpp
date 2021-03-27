// 1038_감소하는_수.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 16

// N: N번째 감소하는 수
// cnt: 감소하는 수의 총 개수
long long N, cnt;
long long decs[1024];

/* 
	{0 ~ 9}의 부분집합으로 만들 수 있는 감소하는 수 = 1개
	=> 총 부분집합(감소하는 수)의 개수 == 2^10 - 1 = 1023 
 */

void dfs(long long num) {
	long long prev = num % 10; // 숫자 붙이기 전 일의 자리 수
	long long cur = num * 10; // 숫자 붙이기 위해 x10

	for (int i = 0; i < prev; i++) {
		decs[cnt++] = cur + i;
		dfs(cur + i);
	}
}

int main() {
	scanf("%lld", &N);

	for (int i = 0; i < 10; i++) {
		decs[cnt++] = i;
		dfs(i);
	}

	sort(decs, decs + cnt);

	// N번째 감소하는 수가 있으면
	if (N < cnt) printf("%lld\n", decs[N]);
	else printf("-1\n");

	return 0;
}
