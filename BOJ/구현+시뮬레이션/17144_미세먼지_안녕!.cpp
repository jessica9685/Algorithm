// 17144_미세먼지_안녕!.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int R, C, T;
int home[MAX][MAX];
int copied[MAX][MAX];
// up, down, left, right
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int clockwise[4] = { 3, 1, 2, 0 };
int counterClock[4] = { 3, 0, 2, 1 };
vector<pair<int, int>> cleaner;

void spread() {
	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// 5 이하의 먼지는 퍼지지 않음
			if (home[i][j] > 4) {
				q.push({ i, j });
			}
		}
	}

	// 배열 복사
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			copied[i][j] = home[i][j];
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int dust = copied[x][y] / 5;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			// 범위 밖
			if (nx >= R || ny >= C || nx < 0 || ny < 0) continue;
			// 공기청정기
			if (copied[nx][ny] == -1) continue;
			
			home[nx][ny] += dust;
			home[x][y] -= dust;
		}
	}
}


void circulate(int a, int b, int direction[]) {
	int x = a;
	int y = b + 1; // 오른쪽부터 이동
	home[x][y] = 0; // 공기청정기에서 나오는 바람은 미세먼지 0

	for (int d = 0; d < 4; d++) {
		while (true) {
			int nx = x + dir[direction[d]][0];
			int ny = y + dir[direction[d]][1];

			// 범위 밖이면 break
			if (!(nx >= 0 && nx < R && ny >= 0 && ny < C)) break;
			if (nx == a && ny == b) { // 공기청정기 위치에 다다르면
				break;
			}

			home[nx][ny] = copied[x][y];
			x = nx;
			y = ny;
		}
	}
}

int main() {
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &home[i][j]);
			if (home[i][j] == -1) { // 공기청정기 있으면
				cleaner.push_back({ i, j });
			}
		}
	}

	for (int t = 1; t <= T; t++) {
		spread(); // 확산
    // 배열 복사
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				copied[i][j] = home[i][j];
			}
		}
    // 
		circulate(cleaner[0].first, cleaner[0].second, counterClock);
		circulate(cleaner[1].first, cleaner[1].second, clockwise);
	}

	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (home[i][j] > 0) {
				sum += home[i][j];
			}
		}
	}

	printf("%d\n", sum);
}
