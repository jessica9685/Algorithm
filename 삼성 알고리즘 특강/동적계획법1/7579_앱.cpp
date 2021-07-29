// 7579_앱.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
int active[101];
int inactive[101];
// 무게 제한이 최대 1000만 -> 공간메모리 부족
// 무게가 아닌 비용으로 dp를 계산해보기
// 앱 개수 100 * 비용 100 = 10000으로 dp 설정
int dp[101][10000];
// dp[앱][비용] = 최대 메모리
// 주어진 비용으로 확보할 수 있는 최대 메모리 크기

int main() {
	scanf("%d %d", &n, &m);

	// 활성 앱이 사용중인 메모리
	for (int i = 1; i <= n; i++) {
		scanf("%d", &active[i]);
	}

	// 비활성화에 드는 비용
	int costSum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inactive[i]);
		costSum += inactive[i];
	}

	// knapsack
	for (int i = 1; i <= n; i++) { // 앱
		for (int j = 0; j <= costSum; j++) { // 목표 비용
			// 갱신이 가능할 때
			if (j - inactive[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - inactive[i]] + active[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	// 최소 M 이상의 공간 확보를 위해 필요한 최소비용 찾기
	for (int i = 0; i <= costSum; i++) {
		if (dp[n][i] >= m) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
