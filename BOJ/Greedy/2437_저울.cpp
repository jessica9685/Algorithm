// 2437_저울.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> weight;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int w;
		scanf("%d", &w);
		weight.push_back(w);
	}

	// 오름차순 정렬
	sort(weight.begin(), weight.end());

	// 1이 없으면 1 출력
	if (weight.front() != 1) {
		printf("1\n");
	}
	else {
		int sum = 1; // 누적합 (sum까지의 무게는 만들 수 있음)
		// if) 1 ~ 4 만들 수 있음
		// 다음 추의 무게가 5이면
		// 5, 1+5 ~ 4+5 까지 만들 수 있음
		for (int i = 1; i < N; i++) {
			if (weight[i] > sum + 1) break;
			sum += weight[i];
		}

		printf("%d\n", sum + 1);
	}

	return 0;
}
