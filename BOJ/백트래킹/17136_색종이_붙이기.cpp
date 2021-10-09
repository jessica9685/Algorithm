// 17136_색종이_붙이기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int paper[10][10];
int usePaper[6] = { 0, 5, 5, 5, 5, 5 };
int paperNum = 0; // 1의 개수
int answer = INF;

bool isCovered(int y, int x, int Size) {
	if ((y + Size > 10) || (x + Size > 10)) return false;

	for (int i = y; i < y + Size; i++) {
		for (int j = x; j < x + Size; j++) {
			if (paper[i][j] != 1) return false;
		}
	}
	return true;
}

void fillPaper(int y, int x, int Size, int state) {
	for (int i = y; i < y + Size; i++) {
		for (int j = x; j < x + Size; j++) {
			paper[i][j] = state;
		}
	}
	// state == 0 (종이 부착)
	if (!state) {
		usePaper[Size]--;
		paperNum -= Size * Size;
	}
	// state == 1 (종이 제거)
	else {
		usePaper[Size]++;
		paperNum += Size * Size;
	}
}

void dfs(int y, int x, int cnt) {
	// 1이 모두 가려지면
	if (paperNum == 0) {
		answer = min(answer, cnt);
		return;
	}

	// 남아있는 1을 모두 탐색
	for (int i = y; i < 10; i++) {
		for (int j = x; j < 10; j++) {
			if (paper[i][j] == 1) {
				// 큰 종이부터 덮을 수 있는지 확인
				for (int k = 5; k > 0; k--) {
					if (isCovered(i, j, k) && usePaper[k] > 0) {
						fillPaper(i, j, k, 0); // 종이 부착
						dfs(i, j + k, cnt + 1); // 다음 dfs
						fillPaper(i, j, k, 1); // 종이 제거
					}
				}
				return; // 없으면 시간초과
			}
		}
		x = 0;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &paper[i][j]);
			if (paper[i][j] == 1) paperNum++;
		}
	}

	dfs(0, 0, 0);
	if (answer == INF) printf("-1\n");
	else printf("%d\n", answer);
	return 0;
}
