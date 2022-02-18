// 13460_구슬_탈출2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 11

int n, m;
char board[MAX][MAX];
char copied[MAX][MAX];
// red, blue 각각의 방문 여부 표시
bool visited[MAX][MAX][MAX][MAX] = { false, }; 
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

typedef struct ballState {
	pair<int, int> red;
	pair<int, int> blue;
	int cnt; // 보드를 움직인 횟수
};

// 보드를 움직였을 때 공이 도착하는 위치 찾기 
pair<int, int> move(pair<int, int> ball, int &cnt, int dir) {
	// 구멍을 만나거나 벽을 만나기 직전까지 이동
	while (board[ball.first][ball.second] != 'O'
		&& board[ball.first + dy[dir]][ball.second + dx[dir]] != '#') {
		ball.first += dy[dir];
		ball.second += dx[dir];
		cnt++; // 몇 칸 이동했는지 계산
	}

	return ball;
}

int main() {
	scanf("%d %d", &n, &m);
	pair<int, int> red, blue;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
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
		pair<int, int> curRed = q.front().red;
		pair<int, int> curBlue = q.front().blue;
		int cnt = q.front().cnt;
		q.pop();

		// 10번 이상 움직이면 break
		if (cnt >= 10) break;

		// 공 이동하기
		for (int i = 0; i < 4; i++) {
			int cntRed = 0, cntBlue = 0;
			pair<int, int> nextRed = move(curRed, cntRed, i);
			pair<int, int> nextBlue = move(curBlue, cntBlue, i);

			// blue가 먼저 구멍에 빠지면 패스
			if (board[nextBlue.first][nextBlue.second] == 'O') continue;
			// red가 먼저 구멍에 빠지면 cnt 리턴 후 종료
			if (board[nextRed.first][nextRed.second] == 'O') {
				printf("%d\n", cnt + 1);
				return 0;
			}

			// blue와 red의 위치가 겹친 경우
			if (nextBlue == nextRed) {
				if (cntRed > cntBlue) { // red가 뒤로
					nextRed.first -= dy[i];
					nextRed.second -= dx[i];
				}
				else { // blue가 뒤로
					nextBlue.first -= dy[i];
					nextBlue.second -= dx[i];
				}
			}

			// 이미 방문한 지점이면 패스
			if (visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second]) continue;
			// 다음 정점 방문하고 큐에 push
			visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second] = true;
			q.push({ nextRed, nextBlue, cnt + 1 });
		}
	}

	// 10번 안에 못빼내면 -1
	printf("-1\n");
	return 0;
}
