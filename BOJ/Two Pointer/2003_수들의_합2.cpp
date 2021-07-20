// 2003_수들의_합2.cpp
// Two Pointer (Sliding Window)
// 시간복잡도 : O(N)
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

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

	while (right < n && left <= right) {
		if (sum < m) {
			right++;
			if (right >= n) break;
			sum += seq[right];
		}
		else if (sum == m) {
			cnt++; // 경우의 수 +1
			right++; // right 이동
			sum += seq[right];
		}
		else { // sum > m
			sum -= seq[left]; 
			left++; // left 이동
			if (left > right) { // 범위를 넘어가면
				right = left; // right를 left로 초기화
				if (right < n) sum = seq[right];
			}
		}
	}

	cout << cnt << endl;
}
