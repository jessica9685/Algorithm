// 2023_신기한_소수.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

bool is_prime(int num) {
	if (num < 2) return false;

	// 2 ~ 루트n까지 반복
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void dfs(int cnt, int num) {
	if (cnt == n) {
		// 소수면 출력
		if (is_prime(num)) printf("%d\n", num);
		return;
	}

	// 1 ~ 9까지 탐색
	for (int i = 1; i < 10; i++) {
		num = num * 10 + i;
		// 새로 만든 수가 소수면 재귀
		if (is_prime(num)) dfs(cnt + 1, num);
		num = (num - i) / 10; // 백트래킹
	}
}

int main() {
	scanf("%d", &n);

	// 소수 2부터 탐색
	for (int i = 2; i < 9; i++) {
		if (is_prime(i)) dfs(1, i);
	}

	return 0;
}
