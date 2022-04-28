// 12100_2048(Easy).cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 21

int n;
int board[MAX][MAX];
int dy[4] = { 1, -1, 0, 0 }; // 아래, 위, 오른쪽, 왼쪽
int dx[4] = { 0, 0, 1, -1 };
int answer = 0;

// 이동
void move(int d) {
	queue<int> q;
	// 위
	if (d == 1) {
		// 왼쪽 열, 위쪽 행 순서대로
		for (int c = 0; c < n; c++) {
			for (int r = 0; r < n; r++) {
				if (board[r][c] != 0) q.push(board[r][c]);
				board[r][c] = 0;
			}

			int row = 0;
			while (!q.empty()) {
				int block = q.front();
				q.pop();

				// 빈칸인 경우
				if (board[row][c] == 0) board[row][c] = block;
				// 윗칸과 같은 숫자면 합치기
				else if (board[row][c] == block) board[row++][c] *= 2;
				// 위에 이미 블록이 있으면 바로 아래 칸에 블록 놓기
				else board[++row][c] = block;
			} 
		}
	}
	// 아래
	else if (d == 0) {
		// 왼쪽 열, 아래쪽 행 순서대로
		for (int c = 0; c < n; c++) {
			for (int r = n - 1; r >= 0; r--) {
				if (board[r][c] != 0) q.push(board[r][c]);
				board[r][c] = 0;
			}

			int row = n - 1;
			while (!q.empty()) {
				int block = q.front();
				q.pop();

				// 빈칸인 경우
				if (board[row][c] == 0) board[row][c] = block;
				// 아래칸과 같은 숫자면 합치기
				else if (board[row][c] == block) board[row--][c] *= 2;
				// 아래에 이미 블록이 있으면 바로 윗칸에 블록 놓기
				else board[--row][c] = block;
			}
		}
	}
	// 오른쪽
	else if (d == 2) {
		//  위쪽 행, 오른쪽 열 순서대로
		for (int r = 0; r < n; r++) {
			for (int c = n - 1; c >= 0; c--) {
				if (board[r][c] != 0) q.push(board[r][c]);
				board[r][c] = 0;
			}

			int col = n - 1;
			while (!q.empty()) {
				int block = q.front();
				q.pop();

				// 빈칸인 경우
				if (board[r][col] == 0) board[r][col] = block;
				// 오른쪽 칸과 같은 숫자면 합치기
				else if (board[r][col] == block) board[r][col--] *= 2;
				// 오른쪽에 이미 블록이 있으면 바로 왼쪽 칸에 블록 놓기
				else board[r][--col] = block;
			}
		}
	}
	// 왼쪽
	else {
		//  위쪽 행, 왼쪽 열 순서대로
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				if (board[r][c] != 0) q.push(board[r][c]);
				board[r][c] = 0;
			}

			int col = 0;
			while (!q.empty()) {
				int block = q.front();
				q.pop();

				// 빈칸인 경우
				if (board[r][col] == 0) board[r][col] = block;
				// 왼쪽칸과 같은 숫자면 합치기
				else if (board[r][col] == block) board[r][col++] *= 2;
				// 왼쪽에 이미 블록이 있으면 바로 오른쪽 칸에 블록 놓기
				else board[r][++col] = block;
			}
		}
	}
}

// 가장 큰 블록 리턴
int maxBlock() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > res) res = board[i][j];
		}
	}

	return res;
}

void dfs(int cnt) {
	// 5번 이동하면 종료
	if (cnt == 5) {
		int res = maxBlock();
		if (answer < res) answer = res;
		return;
	}

	int temp[MAX][MAX]; // 현재 보드 상태 저장
	memcpy(temp, board, sizeof(board));

	for (int d = 0; d < 4; d++) {
		move(d); // 이동
		dfs(cnt + 1); // 다음 단계
		memcpy(board, temp, sizeof(temp)); // 되돌리기
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", answer);
	return 0;
}
