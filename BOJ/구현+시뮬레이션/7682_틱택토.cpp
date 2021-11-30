// 7682_틱택토.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char board[3][3];
int dy[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dx[8] = { -1, 0, 1, 1, -1, -1, 0, 1 };

bool bingo(char c) {
	// 가로
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == c && board[i][1] == c 
			&& board[i][2] == c) return true;
	}

	// 세로
	for (int j = 0; j < 3; j++) {
		if (board[0][j] == c && board[1][j] == c 
			&& board[2][j] == c) return true;
	}

	// 대각선
	if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
	if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;

	return false;
}

// 최종 상태이면 true
bool check(string s) {
	int idx;
	int x = 0, o = 0, blank = 0; // x, o 개수
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			idx = (i * 3) + j;
			board[i][j] = s[idx];

			// O, X, 빈칸의 개수 저장
			if (board[i][j] == 'O') o++;
			else if (board[i][j] == 'X') x++;
			else blank++;
		}
	}

	// 1. O가 X보다 많거나, X가 O보다 2개 이상 많으면 false
	if (o > x || x >= o + 2) return false;

	// 2. 빈칸이 없는 경우
	if (blank == 0) {
		// O가 이기거나 둘 다 이기면 false
		if (bingo('O') && !bingo('X')) return false;
		else if (bingo('O') && bingo('X')) return false;
		else return true;
	}

	// 3. 빈칸이 있는 경우
	else {
		// X가 이길 때
		if (x == o + 1) {
			if (bingo('X') && !bingo('O')) return true;
			else return false;
		}
		// O가 이길 때
		else if (x == o) {
			if (bingo('O') && !bingo('X')) return true;
			else return false;
		}
	}

	return false;
}

int main() {
	while (true) {
		string state;
		cin >> state;

		// end면 종료
		if (state == "end") break;

		if (check(state)) printf("valid\n");
		else printf("invalid\n");
	}
	return 0;
}
