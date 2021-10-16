// 2023_신기한_소수.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

bool isPrime(int num) {
	if (num < 2) return false;

	// 2 ~ 루트n까지 반복
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void dfs(int num, int cnt) {
	if (cnt == n) {
		printf("%d\n", num);
		return;
	}

	// 첫 자리는 소수, 그 이후는 모두 홀수여야 함
	for (int i = 1; i <= 9; i += 2) {
		if (isPrime(num * 10 + i)) {
			dfs(num * 10 + i, cnt + 1);
		}
	}
}

int main() {
	scanf("%d", &n);

	// 첫 자리는 무조건 소수
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}
