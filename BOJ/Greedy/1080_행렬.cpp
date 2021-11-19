// 1080_행렬.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int n, m;
int a[MAX][MAX];
int b[MAX][MAX];
bool transmit[MAX][MAX] = { false, };

// 0 -> 1, 1 -> 0으로 바꾸는 연산
void calc(int row, int col) {
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			transmit[i][j] = !transmit[i][j];
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	// 행렬 A
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	// 행렬 B
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &b[i][j]);
			// 다른 부분을 표시
			if (a[i][j] != b[i][j]) {
				transmit[i][j] = true;
			}
		}
	}
	
	int cnt = 0;
	// 연산 불가능한 행렬이면
	if (n < 3 || m < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// a와 b가 다르면
				if (transmit[i][j]) {
					cnt = -1;
					break;
				}
			}
		}
	}
	// 연산 가능할 때
	else {
		for (int i = 0; i <= n - 3; i++) {
			for (int j = 0; j <= m - 3; j++) {
				// a와 b가 다른 부분이 있으면
				if (transmit[i][j]) {
					calc(i, j);
					cnt++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// a와 b가 다르면
			if (transmit[i][j]) {
				cnt = -1;
				break;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
