// 2110_공유기_설치.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> home;

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		home.push_back(x);
	}
	sort(home.begin(), home.end());

	int left = 0; // 최소 간격
	int right = home[n - 1] - 1; // 최대 간격
	int ans = 0; // 가장 인접한 공유기 간격 최댓값

	while (left <= right) {
		// 1번째 집에는 무조건 공유기 설치
		int start = home[0];
		int router = 1; // 공유기 개수
		int mid = (left + right) / 2;

		for (int i = 1; i < n; i++) {
			int end = home[i];

			// 두 공유기간 간격이 mid 이상이면
			if (end - start >= mid) {
				router++;
				start = end;
			}
		}

		// 설치된 공유기 개수가 c개 이상이면
		if (router >= c) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		// c개 미만이면
		else right = mid - 1;
	}

	printf("%d\n", ans);
	return 0;
}
