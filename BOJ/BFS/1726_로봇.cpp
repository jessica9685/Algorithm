// 1726_로봇.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

typedef struct Robot {
	int y;
	int x;
	int d;
	int cnt; // 명령 횟수
};

int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX][5] = { false, };
int sy, sx, sd; // 출발점
int ey, ex, ed; // 도착점

// 1: 동, 2: 서, 3: 남, 4: 북
int dy[5] = { 0, 0, 0, 1, -1 };
int dx[5] = { 0, 1, -1, 0, 0 };

int rotate_right(int dir) {
	if (dir == 1) dir = 3;
	else if (dir == 2) dir = 4;
	else if (dir == 3) dir = 2;
	else dir = 1;

	return dir;
}

int rotate_left(int dir) {
	if (dir == 1) dir = 4;
	else if (dir == 2) dir = 3;
	else if (dir == 3) dir = 1;
	else dir = 2;

	return dir;
}

int bfs(int start_y, int start_x, int start_dir) {
	queue<Robot> q;
	visited[start_y][start_x][start_dir] = true;
	q.push({ start_y, start_x, start_dir, 0 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		int cnt = q.front().cnt;
		q.pop();

		if (y == ey && x == ex && d == ed) return cnt;

		// 1. Go k
		for (int k = 1; k <= 3; k++) {
			int ny = y + k * dy[d];
			int nx = x + k * dx[d];

			if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
			/* 
				만약 1칸 갔을 때 0, 2칸 1, 3칸 0이면
				3칸은 갈 수 없음 (2칸까지 갈 수 없기 때문)
			*/
			if (board[ny][nx] == 1) break;
			if (!visited[ny][nx][d]) {
				visited[ny][nx][d] = true;
				q.push({ ny, nx, d, cnt + 1 });
			}
		}

		// 2. Turn dir
		// right
		int rd = rotate_right(d);
		if (!visited[y][x][rd]) {
			visited[y][x][rd] = true;
			q.push({ y, x, rd, cnt + 1 });
		}
		// left
		int ld = rotate_left(d);
		if (!visited[y][x][ld]) {
			visited[y][x][ld] = true;
			q.push({ y, x, ld, cnt + 1 });
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	scanf("%d %d %d", &sy, &sx, &sd);
	scanf("%d %d %d", &ey, &ex, &ed);

	int answer = bfs(sy, sx, sd);
	printf("%d\n", answer);
	return 0;
}
