// 3055_탈출.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 50

int r, c;
// 물 == *, 돌 == X, 비버굴 == D, 고슴도치 == S
char map[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int waterTime[MAX][MAX] = { 0, };
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int ea, eb, sa, sb;
queue<pair<int, int>> waterQ;

// 물이 차는 시간 체크
void water_bfs() {
	while (!waterQ.empty()) {
		int x = waterQ.front().first;
		int y = waterQ.front().second;
		waterQ.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (waterTime[nx][ny] == 0 && map[nx][ny] == '.') {
				waterTime[nx][ny] = waterTime[x][y] + 1;
				waterQ.push({ nx, ny });
			}
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a, b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (visited[nx][ny] > 0 || map[nx][ny] == 'X' || map[nx][ny] == '*') continue;
			if (map[nx][ny] == '.' || map[nx][ny] == 'D') {
				// 도착점이거나 물이 차기 전일 경우
				if (waterTime[nx][ny] > visited[x][y] + 1 || waterTime[nx][ny] == 0) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
}


int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'D') {
				ea = i;
				eb = j;
			}
			else if (map[i][j] == 'S') {
				sa = i;
				sb = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == '*') {
				waterQ.push({ i, j });
			}
		}
	}

	water_bfs();
	bfs(sa, sb);

	if (visited[ea][eb] == 0) printf("KAKTUS\n");
	else printf("%d\n", visited[ea][eb]);

	return 0;
}
