// 2096_내려가기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
int dp_min[3];
int dp_max[3];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int p1_min, p2_min, p3_min; // 이전 행 상태 (최소값)
		int p1_max, p2_max, p3_max; // 이전 행 상태 (최대값)
		int c1, c2, c3; // 현재 행 상태
		scanf("%d %d %d", &c1, &c2, &c3);

		p1_min = dp_min[0], p2_min = dp_min[1], p3_min = dp_min[2];
		p1_max = dp_max[0], p2_max = dp_max[1], p3_max = dp_max[2];

		// 최소값
		dp_min[0] = c1 + min(p1_min, p2_min);
		dp_min[1] = c2 + min(p1_min, min(p2_min, p3_min));
		dp_min[2] = c3 + min(p2_min, p3_min);

		// 최대값
		dp_max[0] = c1 + max(p1_max, p2_max);
		dp_max[1] = c2 + max(p1_max, max(p2_max, p3_max));
		dp_max[2] = c3 + max(p2_max, p3_max);
	}

	int minScore = min(dp_min[0], min(dp_min[1], dp_min[2]));
	int maxScore = max(dp_max[0], max(dp_max[1], dp_max[2]));
	printf("%d %d", maxScore, minScore);
	return 0;
}
