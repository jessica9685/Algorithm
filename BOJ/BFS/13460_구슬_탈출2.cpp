// 13460_구슬_탈출2.cpp
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

pair<int, int> move(pair<int, int> ball, int& c, int dir) {
	while (board[ball.first][ball.second] != 'O'
		&& board[ball.first + dy[dir]][ball.second + dx[dir]] != '#') {
		ball.first += dy[dir];
		ball.second += dx[dir];
		c++;
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

	queue<ballState> q;
	q.push({ red, blue, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;

	while (!q.empty()) {
		pair<int, int> curRed = q.front().red;
		pair<int, int> curBlue = q.front().blue;
		int cnt = q.front().cnt;
		q.pop();

		// 10번이 넘어가면 break
		if (cnt >= 10) break;

		for (int i = 0; i < 4; i++) {
			int cntRed = 0, cntBlue = 0;
			pair<int, int> nextRed = move(curRed, cntRed, i);
			pair<int, int> nextBlue = move(curBlue, cntBlue, i);

			// 파란 구슬이 먼저 구멍에 빠지면 continue
			if (board[nextBlue.first][nextBlue.second] == 'O') continue;
			// 빨간 구슬이 구멍에 빠지면 횟수 리턴
			if (board[nextRed.first][nextRed.second] == 'O') {
				printf("%d\n", cnt + 1);
				return 0;
			}

			// 파란 구슬과 빨간 구슬 위치가 겹칠 경우
			if (nextRed == nextBlue) {
				if (cntRed > cntBlue) { // 빨강이 뒤로
					nextRed.first -= dy[i];
					nextRed.second -= dx[i];
				}
				else { // 파랑이 뒤로
					nextBlue.first -= dy[i];
					nextBlue.second -= dx[i];
				}
			}

			// 이미 방문했으면 continue
			if (visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second]) continue;
			// 다음 정점 큐에 push
			visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second] = true;
			q.push({ nextRed, nextBlue, cnt + 1 });
		}
	}

	// 10번 안해 빼낼 수 없으면 -1
	printf("-1\n");
	return 0;
}
