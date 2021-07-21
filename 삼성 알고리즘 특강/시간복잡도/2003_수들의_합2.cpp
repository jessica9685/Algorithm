// 2003_수들의_합2.cpp
// Two Pointer (Sliding Window)
// 시간복잡도 : O(N)
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000 + 1

int n;
long long m;
int seq[MAX];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> seq[i];

	int left = 0;
	int right = 0;
	long long sum = seq[0];
	int cnt = 0;

	while (true) {
		if (sum == m) {
			cnt++;
			sum -= seq[left++];
		}
		else if (sum > m) {
			sum -= seq[left++];
		}
		else {
			sum += seq[++right];
		}

		if (right == n) break;
	}

	cout << cnt << endl;
}
