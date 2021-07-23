// 1837_암호제작.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

typedef long long ll;
string p; // p의 범위가 10^100이기 때문..
ll k; // 1e6까지
vector<int> primes;

// num이 k 이하의 소수로 나눠지면 true
bool isBad(int num) {
	int sum = 0;
	// 한 자리수씩 나누어보기
	for (int i = 0; i < p.length(); i++) {
		sum = (sum * 10 + (p[i] - '0')) % num;
	}
	if (sum == 0) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> p >> k;

	// 에라토스테네스의 체
	// 구해야 하는 소수 범위 = 2 ~ k
	bool checked[MAX + 1] = { false, };
	for (int i = 2; i < k; i++) {
		if (!checked[i]) {
			primes.push_back(i); // 방문한 적 없으면 소수
			// 소수가 아닌 배수 모두 방문
			for (int j = i * 2; j < k; j += i) {
				checked[j] = true;
			}
		}
	}

	for (int prime : primes) {
		// k 이하의 소수로 나눠지면 bad
		if (isBad(prime)) {
			printf("BAD %d\n", prime);
			return 0;
		}
	}
	printf("GOOD\n");
	return 0;
}
