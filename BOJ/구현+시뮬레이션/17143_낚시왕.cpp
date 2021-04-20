// 17143_낚시왕.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int R, C, M;
// 위(1), 아래(2), 오른쪽(3), 왼쪽(4)
int dir[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
typedef struct shark {
	int r, c; // location
	int s; // speed
	int d; // dir
	int z; // size
};

vector<shark> sea[MAX][MAX];

int main() {
	scanf("%d %d %d", &R, &C, &M);
	// 상어 정보 입력
	for (int i = 0; i < M; i++) { 
		shark Shark;
		scanf("%d %d %d %d %d", &Shark.r, &Shark.c, &Shark.s, &Shark.d, &Shark.z);
		sea[Shark.r][Shark.c].push_back(Shark);
	}

	int ans = 0; // 잡은 상어 크기 합
	for (int c = 1; c <= C; c++) { // 낚시꾼 이동
		/* 가장 가까운 상어 잡기 */
		for (int i = 1; i <= R; i++) { 
			if (sea[i][c].size() > 0) {
				ans += sea[i][c][0].z; // 상어 잡고
				sea[i][c].clear(); // 없애기
				break;
			}
		}

		/* 상어 이동 */
		queue<shark> q;
		for (int i = 1; i <= R; i++) { // 상어들 큐에 넣고 지우기
			for (int j = 1; j <= C; j++) {
				if (sea[i][j].size() > 0) {
					q.push(sea[i][j][0]);
					sea[i][j].clear();
				}
			}
		}

		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int s = q.front().s;
			int d = q.front().d;
			int z = q.front().z;
			q.pop();

			// up, down
			if (d == 1 || d == 2) {
				int cycle = (R - 1) * 2;
				if (s >= cycle) s %= cycle;
				for (int i = 0; i < s; i++) {
					int nr = r + dir[d][0];
					if (nr > R || nr < 1) { // 범위 벗어나면
						d = 3 - d; // 방향 반대로
					}
					r += dir[d][0];
				}
			}
			// right, left
			else if (d == 3 || d == 4) {
				int cycle = (C - 1) * 2;
				if (s >= cycle) s %= cycle;
				for (int i = 0; i < s; i++) {
					int nc = c + dir[d][1];
					if (nc > C || nc < 1) { // 범위 벗어나면
						d = 7 - d; // 방향 반대로
					}
					c += dir[d][1];
				}
			}

			/* 시간초과
			for (int i = 0; i < s; i++) {
				// up, down
				if (d == 1 || d == 2) {
					int nr = r + dir[d][0];
					if (nr > R || nr < 1) { // 범위 벗어나면
						d = 3 - d; // 방향 반대로
					}
					r += dir[d][0];
				}
				// right, left
				else if (d == 3 || d == 4) {
					int nc = c + dir[d][1];
					if (nc > C || nc < 1) { // 범위 벗어나면
						d = 7 - d; // 방향 반대로
					}
					c += dir[d][1];
				}
			}
			*/
      
			// 이동한 칸에 이미 상어가 있으면
			if (sea[r][c].size() > 0) {
				// 이미 해당 칸에 있는 상어보다 크기가 더 클 경우
				if (sea[r][c][0].z < z) {
					sea[r][c].clear();
					shark Shark;
					Shark.r = r;
					Shark.c = c;
					Shark.s = s;
					Shark.d = d;
					Shark.z = z;
					sea[r][c].push_back(Shark);
				}
			}
			else {
				shark Shark;
				Shark.r = r;
				Shark.c = c;
				Shark.s = s;
				Shark.d = d;
				Shark.z = z;
				sea[r][c].push_back(Shark);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
