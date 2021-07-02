// 1715_카드_정렬하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	// 카드 세는 횟수 오름차순 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int card;
		scanf("%d", &card);
		pq.push(card);
	}
	
	int ans = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		// 카드 합치고
		ans += (a + b);
		// 큐에 추가
		pq.push(a + b);
	}

	printf("%d\n", ans);
	return 0;
}
