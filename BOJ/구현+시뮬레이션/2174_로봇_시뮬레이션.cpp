// 2174_로봇_시뮬레이션.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int ground[MAX][MAX];
int a, b, n, m;
/* 동(0), 남(1), 서(2), 북(3) */
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
struct robot {
	int x, y, d;
};

int main() {
	// 오른쪽 방향으로 90도 회전했다고 가정
	// 1행 1열이 (1, 1)이도록!
	// 가로 a, 세로 b
	scanf("%d %d %d %d", &a, &b, &n, &m);

	vector<robot> robots(n + 1);
	for (int i = 1; i <= n; i++) {
		char d;
		scanf("%d %d %c", &robots[i].x, &robots[i].y, &d);
		if (d == 'E') robots[i].d = 1; // east
		else if (d == 'S') robots[i].d = 2; // south
		else if (d == 'W') robots[i].d = 3; // west
		else robots[i].d = 0; // north
		ground[robots[i].x][robots[i].y] = i;
	}

	while (m--) {
		int num, cnt;
		char cmd;
		scanf("%d %c %d", &num, &cmd, &cnt);

		/* 직진인 경우 */
		if (cmd == 'F') { 
			for (int i = 0; i < cnt; i++) {
				int nx = robots[num].x + dir[robots[num].d][0];
				int ny = robots[num].y + dir[robots[num].d][1];

				/* 벽에 충돌할 때 */
				if (nx < 1 || ny < 1 || nx > a || ny > b) {
					printf("Robot %d crashes into the wall\n", num);
					return 0;
				}
				/* 다른 로봇이랑 충돌할 때 */
				else if (ground[nx][ny] != 0) {
					printf("Robot %d crashes into robot %d\n", num, ground[nx][ny]);
					return 0;
				}

				ground[robots[num].x][robots[num].y] = 0;
				robots[num].x = nx;
				robots[num].y = ny;
				ground[nx][ny] = num;
			}
		}

		/* 회전인 경우 */
		else {
			if (cnt % 4 == 0) continue; // 4번 회전하면 같은 방향
			cnt %= 4;
			while(cnt--) {
				if (cmd == 'R') { // right rotate 
					robots[num].d = (robots[num].d + 1) % 4;
				}
				else { // left rotate
					if (robots[num].d == 0) robots[num].d = 3;
					else robots[num].d = (robots[num].d - 1) % 4;
				}
			}
		}
	}

	printf("OK\n");
}
