// 13459_구슬_탈출.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int n, m;
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX] = { false, };
int dy[4] = { 0, 0, -1, 1 }; // 왼, 오, 위, 아래
int dx[4] = { -1, 1, 0, 0 };

typedef struct ballState {
	pair<int, int> red;
	pair<int, int> blue;
	int cnt;
};

pair<int, int> move(pair<int, int> ball, int &c, int dir) {
	// 벽이나 구멍을 만날 때까지 이동
	while (board[ball.first + dy[dir]][ball.second + dx[dir]] != '#'
		&& board[ball.first][ball.second] != 'O') {
		ball.first += dy[dir];
		ball.second += dx[dir];
		c += 1; // 이동한 칸 개수
	}

	return ball;
}

int main() {
	scanf("%d %d", &n, &m);

	pair<int, int> red, blue;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &board[i][j]);
			if (board[i][j] == 'R') {
				red = make_pair(i, j);
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				blue = make_pair(i, j);
				board[i][j] = '.';
			}
		}
	}

	// bfs
	queue<ballState> q;
	q.push({ red, blue, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;

	while (!q.empty()) {
		pair<int, int> curR = q.front().red;
		pair<int, int> curB = q.front().blue;
		int cnt = q.front().cnt;
		q.pop();

		// 10회가 넘어가면 break
		if (cnt >= 10) break;

		for (int i = 0; i < 4; i++) {
			int cntR = 0, cntB = 0; // 각 구슬이 이동한 칸 개수
			pair<int, int> nextR = move(curR, cntR, i);
			pair<int, int> nextB = move(curB, cntB, i);

			// 파란 공이 먼저 구멍에 빠진 경우 continue
			if (board[nextB.first][nextB.second] == 'O') continue;
			// 빨간 공이 구멍에 빠진 경우 1 출력 후 종료
			if (board[nextR.first][nextR.second] == 'O') {
				printf("1\n");
				return 0;
			}

			// 빨간 공과 파란 공의 위치가 같은 경우
			if (nextR == nextB) {
				if (cntR > cntB) { // 빨간공이 더 뒤
					nextR.first -= dy[i];
					nextR.second -= dx[i];
				}
				else {
					nextB.first -= dy[i];
					nextB.second -= dx[i];
				}
			}

			// 이미 방문했으면 continue
			if (visited[nextR.first][nextR.second][nextB.first][nextB.second]) continue;
			// 구슬 움직이기
			visited[nextR.first][nextR.second][nextB.first][nextB.second] = true;
			q.push({ nextR, nextB, cnt + 1 });
		}
	}

	// while문을 빠져나오면 0 출력
	printf("0\n");
	return 0;
}
