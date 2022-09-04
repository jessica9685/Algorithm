// 2812_크게_만들기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
 
int n, k;
vector<int> num;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%1d", &x);
		num.push_back(x);
	}

	deque<int> dq;
	for (int i = 0; i < n; i++) {
		// k가 0이 될 때까지, dq의 맨 끝 숫자가 현재 숫자보다 작으면 pop
		while (k > 0 && !dq.empty() && dq.back() < num[i]) {
			dq.pop_back();
			k--;
		}
		dq.push_back(num[i]); // deque에 push
	}

	// 반복문을 빠져나왔을 때 k가 남아있을 수 있으므로
	// index 0 ~ dq.size - k - 1까지의 수를 출력
	for (int i = 0; i < dq.size() - k; i++) {
		printf("%d", dq[i]);
	}
	printf("\n");
	return 0;
}
