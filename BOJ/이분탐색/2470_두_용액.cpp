// 2470_두_용액.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> liquid;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		liquid.push_back(x);
	}

	sort(liquid.begin(), liquid.end());

	// 양 끝 인덱스
	int left = 0;
	int right = n - 1;
	// 범위가 10억이므로 최대 20억
	int mix_res = 2000000001;
	// 두 용액
	int l1 = liquid[left];
	int l2 = liquid[right];

	while (left < right) {
		int mix = liquid[left] + liquid[right];

		// 혼합 결과가 0이면 종료
		if (mix == 0) {
			l1 = liquid[left];
			l2 = liquid[right];
			break;
		}
		else {
			// 절대값 비교해 갱신
			if (mix_res > abs(mix)) {
				mix_res = abs(mix);
				l1 = liquid[left];
				l2 = liquid[right];
			}

			if (mix < 0) left++;
			else right--;
		}
	}

	printf("%d %d\n", l1, l2);
	return 0;
}
