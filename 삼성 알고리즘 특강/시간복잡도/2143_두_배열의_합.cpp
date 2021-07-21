// 2143_두_배열의_합.cpp
// Two Pointer
// 시간복잡도 : O(N^2)
// 만약 브루트포스로 하면 O(N^4)일 것...
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

typedef long long ll;

ll T;
int n, m;

bool comp(ll a, ll b) {
	return a > b;
}

int main() {
	scanf("%lld", &T);

	scanf("%d", &n);
	vector<ll> A(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &A[i]);
	}

	scanf("%d", &m);
	vector<ll> B(m);
	for (int i = 0; i < m; i++) {
		scanf("%lld", &B[i]);
	}

	// A의 부배열 합
	vector<ll> subA;
	for (int i = 0; i < n; i++) {
		ll sum = A[i];
		subA.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += A[j];
			subA.push_back(sum);
		}
	}

	// B의 부배열 합
	vector<ll> subB;
	for (int i = 0; i < m; i++) {
		ll sum = B[i];
		subB.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += B[j];
			subB.push_back(sum);
		}
	}

	sort(subA.begin(), subA.end()); // subA는 오름차순 정렬
	sort(subB.begin(), subB.end(), comp); // subB는 내림차순 정렬
	
	int a = 0; // subA의 포인터
	int b = 0; // subB의 포인터
	ll cnt = 0; // int 범위를 초과하므로 long long 선언

	while (a < subA.size() && b < subB.size()) {
		ll curA = subA[a];
		ll target = T - curA;
		if (subB[b] > target) {
			b++;
		}
		else if (subB[b] == target) {
			ll cntA = 0; // subA의 중복 숫자 개수 
			ll cntB = 0; // subB의 중복 숫자 개수
			while (a < subA.size() && subA[a] == curA) {
				a++;
				cntA++;
			}
			while (b < subB.size() && subB[b] == target) {
				b++;
				cntB++;
			}
			cnt += (cntA * cntB);
		}
		else { // subB[b] < target
			a++;
		}
	}

	printf("%lld\n", cnt);
	return 0;
}
