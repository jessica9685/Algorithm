// 20056_마법사_상어와_파이어볼.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int n, m, K;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

typedef struct fireball {
	int r;
	int c; // 위치
	int m; // 질량
	int s; // 속도
	int d; // 방향
};

vector<fireball> grid[MAX][MAX];
vector<fireball> fb; // 파이어볼 저장

int main() {
	scanf("%d %d %d", &n, &m, &K);
	for (int i = 0; i < m; i++) {
		fireball f;
		scanf("%d %d %d %d %d", &f.r, &f.c, &f.m, &f.s, &f.d);
		grid[f.r][f.c].push_back(f);
		fb.push_back(f);
	}

	while (K--) {
		/* 1. 모든 파이어볼 이동 */
		// 격자판 비우기
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) grid[i][j].clear();
		}

		// 파이어볼 이동하기
		for (int i = 0; i < fb.size(); i++) {
			fireball f = fb[i];
			int nr = f.r + (f.s % n) * dx[f.d];
			int nc = f.c + (f.s % n) * dy[f.d];
			if (nr > n) nr -= n;
			if (nr < 1) nr += n;
			if (nc > n) nc -= n;
			if (nc < 1) nc += n;

			f.r = nr;
			f.c = nc;

			grid[nr][nc].push_back(f); // 격자판에 넣기
			fb[i].r = nr;
			fb[i].c = nc; 
		}

		/* 2. 파이어볼 나누기 */
		vector<fireball> tmp;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (grid[i][j].size() == 0) continue;
				else if (grid[i][j].size() == 1) {
					tmp.push_back(grid[i][j][0]);
					continue;
				}
				// 한 칸에 있는 파이어볼이 2개 이상일 때
				int massSum = 0;
				int speedSum = 0;

				bool odd = true; // 모두 홀수면 true
				bool even = true; // 모두 짝수면 true

				for (int k = 0; k < grid[i][j].size(); k++) {
					massSum += grid[i][j][k].m;
					speedSum += grid[i][j][k].s;
					if (grid[i][j][k].d % 2 == 0) odd = false;
					else even = false;
				}

				int mass = massSum / 5;
				int speed = speedSum / grid[i][j].size();
				if (mass == 0) continue; // 질량 0이면 없어짐
				if (even || odd) {
					for (int k = 0; k < 4; k++) tmp.push_back({ i, j, mass, speed, k * 2 });
				}
				else {
					for (int k = 0; k < 4; k++) tmp.push_back({ i, j, mass, speed, k * 2 + 1 });
				}
			}
		}
		fb = tmp;
	}

	int ans = 0;
	for (int i = 0; i < fb.size(); i++) {
		ans += fb[i].m;
	}

	printf("%d\n", ans);
}
