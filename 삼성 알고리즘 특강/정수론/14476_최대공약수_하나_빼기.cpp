// 14476_최대공약수_하나_빼기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// gcd(a, b) == gcd(b, a % b)
ll gcd(ll a, ll b) {
	while (b != 0) {
		ll r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int n;
vector<ll> numbers;

int main() {
	scanf("%d", &n);
	
	numbers.resize(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &numbers[i]);
	}

	// 왼쪽에서 오른쪽으로 gcd 누적합 (0 ~ i까지의 최대공약수)
	vector<ll> LtoR(n, 0); 
	LtoR[0] = numbers[0];

	// 오른쪽에서 왼쪽으로 gcd 누적합 (n - 1 ~ i까지의 최대공약수)
	vector<ll> RtoL(n, 0); 
	RtoL[n - 1] = numbers[n - 1];
	
	for (int i = 1; i < n; i++) {
		LtoR[i] = gcd(LtoR[i - 1], numbers[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		RtoL[i] = gcd(RtoL[i + 1], numbers[i]);
	}
	
	// 초기값: 첫번째 수를 뺐을 때
	ll maxGcd = RtoL[1];
	ll removed = numbers[0];

	for (int i = 1; i < n - 1; i++) {
		ll tempGcd = gcd(LtoR[i - 1], RtoL[i + 1]);
		if (maxGcd < tempGcd) {
			maxGcd = tempGcd;
			removed = numbers[i];
		}
	}
	// 마지막 수를 뺀 결과가 최대일 때
	if (maxGcd < LtoR[n - 1]) {
		maxGcd = LtoR[n - 2];
		removed = numbers[n - 1];
	}

	// 뺀 수의 약수가 maxGcd이면 정답 없음
	if (removed % maxGcd == 0) printf("%d\n", -1);
	else {
		printf("%lld %lld\n", maxGcd, removed);
	}
	return 0;
}
