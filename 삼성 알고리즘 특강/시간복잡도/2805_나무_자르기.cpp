// 2805_나무_자르기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

typedef long long ll;

ll n, m;
vector<ll> tree;

int main() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < n; i++) {
		ll t;
		scanf("%lld", &t);
		tree.push_back(t);
	}

	sort(tree.begin(), tree.end());

	ll answer = 0;
	ll left = 1;
	ll right = tree[n - 1];

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;

		for (auto t : tree) {
			if (t > mid) sum += (t - mid);
		}

		// 문제 조건 : 최소 M미터 이상의 나무를 가져가야 함 
		if (sum >= m) { // 조건을 충족하면
			answer = max(answer, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%lld\n", answer);
	return 0;
}
