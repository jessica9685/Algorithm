// 14003_가장_긴_증가하는_부분_수열5.cpp
// LIS
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> seq;
vector<int> pos; // pos[i] = seq[i]가 lis에 들어갔을 때의 lis 인덱스
vector<int> lis; // 증가하는 부분 수열

int main() {
	scanf("%d", &N);

	seq.resize(N);
	pos.resize(N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &seq[i]);
	}

	lis.push_back(seq[0]);
	for (int i = 1; i < N; i++) {
		// lis가 비어있거나 현재 원소가 lis의 마지막 값보다 크면 -> 그대로 넣기
		if (seq[i] > lis.back()) {
			lis.push_back(seq[i]);
			pos[i] = lis.size() - 1;
		}
		// lis의 마지막 값보다 현재 원소가 작으면
		else {
			//-> lis 배열 탐색(lower-bound)
			auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
			int low = it - lis.begin();
			// lis 갱신
			lis[low] = seq[i];
			// pos에 lis 위치 추가
			pos[i] = low;
		}
	}


	// pos 배열을 거꾸로 탐색하면서 lis를 찾음
	stack<int> ans;
	int idx = lis.size() - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (pos[i] == idx) {
			ans.push(seq[i]);
			idx--;
		}
		if (idx < 0) break;
	}

	int len = lis.size();
	printf("%d\n", len);
	while (!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}
