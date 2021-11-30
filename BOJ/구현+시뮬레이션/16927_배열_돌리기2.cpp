// 16927_배열_돌리기2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 301

int n, m, R;
int board[MAX][MAX];

void rotate(int r) {
	// 테두리 꼭짓점
	int y1 = 0, x1 = 0;
	int y2 = n - 1, x2 = 0;
	int y3 = n - 1, x3 = m - 1;
	int y4 = 0, x4 = m - 1;

	while ((y1 < y2) && (x1 < x4)) {
		// 회전 횟수 구하기 (mod)
		// ex. n = 4, m = 5일 때, 1번 회전한 결과와 15번 회전한 결과는 같음 
		int cnt = r % ((y2 - y1) * 2 + (x4 - x1) * 2);

		// 회전
		while (cnt--) {
			// 배열 복사 방식은 시간초과 발생
			// 별도의 배열 복사 없이 그대로 진행
			int temp = board[y1][x1];

			// 반시계 방향으로 회전
			// y1행
			for (int j = x1; j < x4; j++) {
				board[y1][j] = board[y1][j + 1];
			}
			// x4열
			for (int i = y4; i < y3; i++) {
				board[i][x4] = board[i + 1][x4];
			}
			// y3행
			for (int j = x3; j > x2; j--) {
				board[y3][j] = board[y3][j - 1];
			}
			// x2열
			for (int i = y2; i > y1; i--) {
				board[i][x2] = board[i - 1][x2];
			}
			board[y1 + 1][x1] = temp;
		}

		// 영역을 안쪽으로 옮기기
		y1++, x1++;
		y2--, x2++;
		y3--, x3--;
		y4++, x4--;
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &R);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	rotate(R);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}
