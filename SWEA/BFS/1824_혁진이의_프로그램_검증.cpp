// SWEA : 1824_혁진이의_프로그램_검증.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 21

typedef struct comm {
	int x, y; // 좌표
	int mem; // 메모리
	int d; // 방향
};

int T;
int r, c;
char commands[MAX][MAX];
bool visited[MAX][MAX][16][4];
// 오른쪽, 왼쪽, 아래, 위
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool bfs() {
	queue<comm> q;
	comm start;
	start.x = 0;
	start.y = 0;
	start.mem = 0;
	start.d = 0;
	visited[0][0][0][0] = true;
	q.push(start);

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int mem = q.front().mem;
		int d = q.front().d;
		q.pop();

		// 숫자인 경우 
		if (commands[x][y] >= '0' && commands[x][y] <= '9') mem = commands[x][y] - '0';

		// 방향 전환
		else if (commands[x][y] == '>') d = 0;
		else if (commands[x][y] == '<') d = 1;
		else if (commands[x][y] == 'v') d = 2;
		else if (commands[x][y] == '^') d = 3;

		// 메모리 변환
		else if (commands[x][y] == '+') mem = (mem + 1) % 16;
		else if (commands[x][y] == '-') mem = mem == 0 ? 15 : mem - 1;

		// 메모리가 0인지 아닌지에 따른 방향 전환
		else if (commands[x][y] == '_') d = mem == 0 ? 0 : 1;
		else if (commands[x][y] == '|') d = mem == 0 ? 2 : 3;

		// 무작위 방향 전환
		else if (commands[x][y] == '?') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];

				// % 연산은 음수일 때 이상하게 나오니까 사용ㄴㄴ
				if (nx == -1) nx = r - 1;
				else if (nx == r) nx = 0;
				if (ny == -1) ny = c - 1;
				else if (ny == c) ny = 0;

				if (!visited[nx][ny][mem][i]) {
					comm next;
					next.x = nx;
					next.y = ny;
					next.mem = mem;
					next.d = i;
					q.push(next);
					visited[nx][ny][mem][i] = true;
				}
			}
		}

		// 프로그램 종료
		else if (commands[x][y] == '@') return true;

		int nx = x + dir[d][0];
		int ny = y + dir[d][1];

		if (nx == -1) nx = r - 1;
		else if (nx == r) nx = 0;
		if (ny == -1) ny = c - 1;
		else if (ny == c) ny = 0;

		if (!visited[nx][ny][mem][d]) {
			comm next;
			next.x = nx;
			next.y = ny;
			next.mem = mem;
			next.d = d;
			q.push(next);
			visited[nx][ny][mem][d] = true;
		}
	}

	return false;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf(" %1c", &commands[i][j]);
			}
		}

		memset(visited, false, sizeof(visited));
		bool answer = bfs();

		if (answer) printf("#%d YES\n", tc);
		else printf("#%d NO\n", tc);
	}

	return 0;
}
