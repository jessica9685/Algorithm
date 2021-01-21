// 1018_체스판_다시_칠하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 50
#define INF 2500

int m, n; // m * n (m행 n열)
int board[MAX][MAX]; // white == 1, black == 0

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char color;
			scanf(" %c", &color);
			if (color == 'W') board[i][j] = 1;
			else board[i][j] = 0;
		}
	}

	int ans = INF;
	for (int i = 0; i <= m - 8; i++) {
		for (int j = 0; j <= n - 8; j++) {
			int black = 0; // 첫 칸이 검정일 때 색 바꾸는 횟수 (행+열 합이 짝수면 black)
			int white = 0; // 첫 칸이 흰색일 때 색 바꾸는 횟수 (행+열 합이 짝수면 white)
			for (int x = i; x < i + 8; x++) {
				for (int y = j; y < j + 8; y++) {
					if ((x + y) % 2 == 0) { // 짝수
						if (board[x][y] == 1) { // 현재 흰색이면
							black++; // 흰 -> 검
						}
						else { // 현재 검은색이면
							white++; // 검 -> 흰
						}
					}
					else { // 홀수
						if (board[x][y] == 1) { // 현재 흰색이면
							white++; // 검 -> 흰
						}
						else { // 현재 검은색이면
							black++; // 흰 -> 검
						}
					}
				}
			}
			int temp = min(black, white);
			ans = min(temp, ans);
		}
	}

	printf("%d\n", ans);
}
