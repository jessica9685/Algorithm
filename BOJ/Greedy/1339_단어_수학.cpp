// 1339_단어_수학.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> vec;
ll alpha[26]; // 알파벳이 몇개 사용되었는지?

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ll cnt = 1;
		// 각 string에 있는 알파벳 개수 세기
		// 100의 자리에 A가 있으면 A가 100개
		for (int j = s.size() - 1; j >= 0; j--) {
			alpha[s[j] - 'A'] += cnt;
			cnt *= 10;
		}
	}

	// 존재하는 알파벳을 vec에 넣기
	for (int i = 0; i < 26; i++) {
		if (alpha[i] != 0) vec.push_back(alpha[i]);
	}

	// 오름차순 정렬
	sort(vec.begin(), vec.end(), greater<ll>());

	// 최대값 계산
	int value = 9;
	ll answer = 0;
	for (auto c : vec) {
		answer += (c * value);
		value--;
	}

	printf("%lld\n", answer);
	return 0;
}
