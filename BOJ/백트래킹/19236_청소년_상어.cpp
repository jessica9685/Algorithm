// 19236_청소년_상어.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct fish {
	int y;
	int x;
	int dir; // 방향
	bool isDead; // 죽으면 true
};

int answer = 0;
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

// board, fish: 원본 배열, (shark_y, shark_x): 상어 위치, sum: 먹은 물고기 총합
void dfs(int board[][4], fish fishes[], int shark_y, int shark_x, int sum) {
	/* 배열 복사 */
	int copy_board[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) copy_board[i][j] = board[i][j];
	}
	fish copy_fishes[17];
	for (int i = 1; i <= 16; i++) copy_fishes[i] = fishes[i];
	
	/* 1. 현재 위치에서 물고기 먹음 */
	int cur = copy_board[shark_y][shark_x];
	copy_board[shark_y][shark_x] = -1; // 빈칸으로 만들기
	copy_fishes[cur].isDead = true; // 물고기 죽음
	sum += cur; // 먹은 물고기 합 추가

	// 상어 이동방향
	int shark_dir = fishes[cur].dir;
	// 최대값 갱신
	if (answer < sum) answer = sum;

	/* 2. 물고기 이동 */
	for (int idx = 1; idx <= 16; idx++) {
		// 물고기가 죽지 않았으면
		if (!copy_fishes[idx].isDead) {
			int y = copy_fishes[idx].y;
			int x = copy_fishes[idx].x;
			int dir = copy_fishes[idx].dir;

			int ny = y + dy[dir];
			int nx = x + dx[dir];

			// 경계를 벗어나거나 상어가 있는 곳이면 방향 바꿈
			while (ny < 0 || nx < 0 || ny >= 4 || nx >= 4
				|| (ny == shark_y && nx == shark_x)) {
				dir = (dir + 1) % 8;
				ny = y + dy[dir];
				nx = x + dx[dir];
			}

			/* 물고기 swap */
			// 물고기 <-> 물고기
			if (copy_board[ny][nx] != -1) {
				int next = copy_board[ny][nx];

				// 기준 물고기의 위치, 방향 갱신
				copy_fishes[idx].y = ny;
				copy_fishes[idx].x = nx;
				copy_fishes[idx].dir = dir;

				// 바뀐 물고기 위치 갱신
				copy_fishes[next].y = y;
				copy_fishes[next].x = x;

				// board에 바뀐 위치 반영
				copy_board[ny][nx] = idx;
				copy_board[y][x] = next;
			}
			// 물고기 <-> 빈칸
			else {
				// 기준 물고기의 위치, 방향 갱신
				copy_fishes[idx].y = ny;
				copy_fishes[idx].x = nx;
				copy_fishes[idx].dir = dir;

				// board에 바뀐 위치 반영
				copy_board[ny][nx] = idx;
				copy_board[y][x] = -1;
			}
		}
	}

	/* 3. 상어 이동 */
	for (int i = 1; i < 4; i++) {
		int ny = shark_y + dy[shark_dir] * i;
		int nx = shark_x + dx[shark_dir] * i;

		// 경계를 벗어나면 pass
		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;	
		// 빈칸이 아니면 이동
		if (copy_board[ny][nx] != -1) {
			dfs(copy_board, copy_fishes, ny, nx, sum);
		}
	}
}

int main() {
	fish fishes[17];
	int board[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			scanf("%d %d", &num, &dir);
			fishes[num] = { i, j, dir - 1, false };
			board[i][j] = num;
		}
	}

	dfs(board, fishes, 0, 0, 0);
	printf("%d\n", answer);
	return 0;
}
