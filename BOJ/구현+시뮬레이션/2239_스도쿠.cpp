// 2239_스도쿠.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int sudoku[9][9]; // idx: 0 ~ 8
// 각 행, 열, 3X3 보드의 숫자 존재 여부 표시
bool row[9][10]; // [행번호][숫자(1~9)]
bool col[9][10]; // [열번호][숫자]
bool square[9][10]; // [3x3 보드 번호(왼쪽 위부터 0)][숫자] 

// 사용된 숫자 표시
// 백트래킹을 위해 false->true, true->false 형태로 작성
void check(int i, int j, int num) {
	row[i][num] = !row[i][num];
	col[j][num] = !col[j][num];
	square[(i / 3) * 3 + (j / 3)][num] = !square[(i / 3) * 3 + (j / 3)][num];
}

// 81개 칸 모두 탐색
void dfs(int cnt) {
	int y = cnt / 9;
	int x = cnt % 9;

	// 모든 칸을 채우면 결과 출력
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d", sudoku[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	// 현재 칸이 빈칸이면
	if (sudoku[y][x] == 0) {
		// 넣을 수 있는 숫자 탐색
		for (int num = 1; num <= 9; num++) {
			// 행, 열, square에 중복되지 않으면
			if (!row[y][num] && !col[x][num] && !square[(y / 3) * 3 + (x / 3)][num]) {
				check(y, x, num); // 방문
				sudoku[y][x] = num;
				dfs(cnt + 1); // 다음 정점 탐색
				check(y, x, num); // 백트래킹
				sudoku[y][x] = 0;
			}
		}
	}
	// 빈칸이 아니면 다음으로
	else dfs(cnt + 1);
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &sudoku[i][j]);
			if (sudoku[i][j] != 0) check(i, j, sudoku[i][j]);
		}
	}

	dfs(0);
	return 0;
}
