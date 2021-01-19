// 1175_배달.cpp
using namespace std;
#include <iostream>;
#include <queue>
#include <algorithm>
#include <string>
#define MAX 50

struct point {
	int x, y; // 좌표
	int dir;
	int c, d;
};

int n, m;
int answer = 0; // 최소 시간

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int visited[MAX][MAX][5][2][2] = { 0, }; // x, y, dir, C, D
char map[MAX][MAX] = { 0, };


void bfs(int sx, int sy) {
	queue<pair<point, int>> q;

	visited[sx][sy][4][0][0] = 1;

	point start;
	start.x = sx;
	start.y = sy;
	start.dir = 4;
	start.c = 0;
	start.d = 0;
	int count = 0;

	q.emplace(start, count);

	while (!q.empty()) {
		point p = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (p.c == 1 && p.d == 1) {
			answer = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			if (p.dir == i) continue; // 방향 같으면 continue

			point np = p;
			np.x = p.x + dir[i][0];
			np.y = p.y + dir[i][1];
			np.dir = i;

			if (np.x < 0 || np.y < 0 || np.x >= n || np.y >= m) continue;
			if (visited[np.x][np.y][i][np.c][np.d] || map[np.x][np.y] == '#') continue;

			if (map[np.x][np.y] == 'C') np.c = 1;
			if (map[np.x][np.y] == 'D') np.d = 1;

			visited[np.x][np.y][np.dir][np.c][np.d] = 1;
			q.emplace(np, cnt + 1);
		}
	}
}

int main() {
	int sx, sy;
	int num = 0; // C의 개수
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &map[i][j]);

			if (map[i][j] == 'S') {
				sx = i;
				sy = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'C') {
				num++;
				if (num == 2) {
					map[i][j] = 'D';
				}
			}
		}
	}

	bfs(sx, sy);

	if (answer == 0) printf("-1\n");
	else printf("%d\n", answer);

	return 0;
}
