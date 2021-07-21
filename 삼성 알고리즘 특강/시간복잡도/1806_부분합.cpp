// 1806_부분합.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
typedef long long ll;

int n;
int seq[MAX];
ll s;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	int len = 0;
	int minLen = 100001;
	int left = 0;
	int right = 0;
	ll sum = seq[0];

	while (right < n && left <= right) {
		if (sum >= s) {
			len = right - left + 1;
			if (minLen > len) minLen = len;
			sum -= seq[left];
			left++;

			if (left > right) {
				right = left;
				if (left < n) sum = seq[left];
			}
		}
		else { // sum < s
			right++;
			if (right >= n) break;
			sum += seq[right];
		}
	}

	if (minLen == 100001) cout << 0 << endl;
	else cout << minLen << endl;
}
