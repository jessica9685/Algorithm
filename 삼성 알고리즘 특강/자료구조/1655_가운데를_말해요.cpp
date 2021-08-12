// 1655_가운데를_말해요.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;
// 최대힙의 크기는 최소힙의 크기보다 1만큼 크거나 같다
// 최소힙의 top >= 최대힙의 top
priority_queue<int> maxHeap; // 최대힙
priority_queue<int, vector<int>, greater<int>> minHeap; // 최소힙

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		
		// 최소힙과 최대힙의 크기가 같은 경우
		if (minHeap.size() == maxHeap.size()) { 
			// 최대힙에 넣어줌
			maxHeap.push(num);
		}
		// 최대힙의 크기가 더 큰 경우
		else {
			// 최소힙에 넣어줌
			minHeap.push(num);
		}

		// 만약 최대힙의 top > 최소힙의 top인 경우
		if (!maxHeap.empty() && !minHeap.empty() 
			&& (maxHeap.top() > minHeap.top())) {
			int a = maxHeap.top(); maxHeap.pop();
			int b = minHeap.top(); minHeap.pop();

			// 두 top 값을 swap
			maxHeap.push(b);
			minHeap.push(a);
		}

		// 최대힙의 top이 중간값
		printf("%d\n", maxHeap.top());
	}
	return 0;
}
