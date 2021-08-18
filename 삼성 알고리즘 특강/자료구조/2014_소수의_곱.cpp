// 2014_소수의_곱.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int K, N;

int main() {
	scanf("%d %d", &K, &N);

	// 소수 배열
	vector<int> primes;
	// 오름차순 우선순위 큐
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < K; i++) {
		int p;
		scanf("%d", &p);
		primes.push_back(p);
		pq.push(p);
	}

	ll ans = 0; // N번째 수

	for (int i = 0; i < N; i++) {
		// n번 pop하면 n번째 수가 됨
		ans = pq.top();
		pq.pop();

		// K개의 수에 대한 소수의 곱 구해서 큐에 push
		for (auto prime : primes) {
			ll value = ans * prime;
			pq.push(value);

			// 중복 제거
			if (ans % prime == 0) break;
		}
	}

	printf("%d\n", ans);
	return 0;
}
