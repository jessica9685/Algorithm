// SWEA : 2819_격자판의_숫자_이어_붙이기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int T;
char board[4][4];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
set<string> numbers;

void dfs(int x, int y, string num, int cnt) {
	if (cnt == 7) {
		numbers.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
		dfs(nx, ny, num + board[nx][ny], cnt + 1);
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf(" %1c", &board[i][j]);
			}
		}

		numbers.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j, to_string(board[i][j]), 1);
			}
		}

		int answer = (int)numbers.size();
		printf("#%d %d\n", tc, answer);
	}

	return 0;
}
