// 2116_주사위_쌓기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int n;
int dice[MAX][7]; 

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf("%d", &dice[i][j]);
		}
	}

	int front[7]; // a, b, c, d, e, f가 마주보는 방향
	front[1] = 6; front[2] = 4; front[3] = 5;
	front[4] = 2; front[5] = 3; front[6] = 1;

	int ans = 0;
	for (int i = 1; i <= 6; i++) {
		int sum = 0;
		int bottom = dice[1][front[i]]; // 1번 주사위의 아랫면
		int top = dice[1][i]; // 1번 주사위의 윗면
		
		// 1번 주사위의 최대값 구하기
		int max1 = 0;
		for (int f = 1; f <= 6; f++) {
			// 윗면과 아랫면을 제외한 나머지 숫자의 최대값 구하기
			if (f != top && f != bottom) {
				max1 = max(max1, f);
			}
		}
		sum += max1;

		// 2 ~ n번 주사위 최댓값 구하기
		for (int j = 2; j <= n; j++) {
			int maxn = 0;
			for (int next = 1; next <= 6; next++) {
				if (dice[j][next] == top) {
					bottom = dice[j][next];
					top = dice[j][front[next]];
					break;
				}
			}

			for (int k = 1; k <= 6; k++) {
				// 윗면과 아랫면을 제외한 나머지 숫자의 최대값 구하기
				if (k != top && k != bottom) {
					maxn = max(maxn, k);
				}
			}
			sum += maxn;
		}

		ans = max(sum, ans);
		sum = 0;
	}
	printf("%d\n", ans);
	return 0;
}
