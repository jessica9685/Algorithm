// 20057_마법사_상어와_토네이도.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int N;
int grid[MAX][MAX];
int ans = 0; // 밖으로 넘어간 모래 양

// left, down, right, up
int da[4] = { 0, 1, 0, -1 };
int db[4] = { -1, 0, 1, 0 };

// (xa, xb) -> (ya, yb)
// left, down, right, up
// 1, 1, 7, 7, 2, 2, 10, 10, 5, a
// (xa, xb) 기준
int dir[4][10][2] = {
	{ {-1, 0}, {1, 0}, {-1, -1}, {1, -1}, {-2, -1}, {2, -1}, {-1, -2}, {1, -2}, {0, -3}, {0, -2} },
	{ {0, -1}, {0, 1}, {1, -1}, {1, 1}, {1, -2}, {1, 2}, {2, -1}, {2, 1}, {3, 0}, {2, 0} },
	{ {-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}, {0, 3}, {0, 2} },
	{ {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {-3, 0}, {-2, 0} }
};
// 각 위치에서의 비율
int ratios[9] = { 1, 1, 7, 7, 2, 2, 10, 10, 5 };

void moveSand(int xa, int xb, int d) {
	int ya = xa + da[d];
	int yb = xb + db[d];

	// 모레가 없으면 종료
	if (grid[ya][yb] == 0) return;
	
	int sand = grid[ya][yb]; // 원래 모래 양
	int tmp = sand;
	// 모래 이동
	for (int i = 0; i < 9; i++) {
		int nx = xa + dir[d][i][0];
		int ny = xb + dir[d][i][1];
		int movedSand = (tmp * ratios[i]) / 100;

		// 격자 밖으로 나간 경우
		if (nx < 1 || ny < 1 || nx > N || ny > N) ans += movedSand;
		else grid[nx][ny] += movedSand; // 범위 내
		sand -= movedSand;
	}

	// a(알파) 부분의 모래
	int nx = xa + dir[d][9][0];
	int ny = xb + dir[d][9][1];

	if (nx < 1 || ny < 1 || nx > N || ny > N) ans += sand;
	else grid[nx][ny] += sand;
	grid[ya][yb] = 0;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &grid[i][j]);
		}
	}

	int x = (N + 1) / 2;
	int y = (N + 1) / 2;
	int d = 0; // left
	int moveCnt = 1;
	
	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < moveCnt; j++) {
				moveSand(x, y, d);
				x += da[d];
				y += db[d];
			}
			d = (d + 1) % 4;
		}

		moveCnt++;

		// 마지막 부분일 때
		if (moveCnt == N) {
			for (int j = 0; j < moveCnt; j++) {
				moveSand(x, y, d);
				x += da[d];
				y += db[d];
			}
			break;
		}
	}

	printf("%d\n", ans);
}
