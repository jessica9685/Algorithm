// 7569_토마토.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

typedef struct state {
	int box;
	int y;
	int x;
};

int m, n, h;
int tomato[MAX][MAX][MAX];
queue<state> q;
int dy[4] = { 1, -1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 };
int answer;

bool is_ripen() {
	for (int k = 0; k < h; k++) { // 상자
		for (int i = 0; i < n; i++) { // 세로
			for (int j = 0; j < m; j++) { // 가로
				// 익지 않은 토마토가 있으면
				if (tomato[k][i][j] == 0) return false;
				else answer = max(answer, tomato[k][i][j]);
			}
		}
	}
	return true;
}

int main() {
	scanf("%d %d %d", &m, &n, &h);
	
	for (int k = 0; k < h; k++) { // 상자
		for (int i = 0; i < n; i++) { // 세로
			for (int j = 0; j < m; j++) { // 가로
				scanf("%d", &tomato[k][i][j]);
				// 이미 익은 토마토는 큐에 push
				if (tomato[k][i][j] == 1) q.push({ k, i, j });
			}
		}
	}

	// 이미 모든 토마토가 익어있으면 0
	if (is_ripen()) {
		printf("0\n");
		return 0;
	}

	while (!q.empty()) {
		state cur = q.front();
		q.pop();

		// 위, 아래, 왼쪽, 오른쪽
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			// 익지 않은 토마토가 있으면
			if (tomato[cur.box][ny][nx] == 0) {
				tomato[cur.box][ny][nx] = tomato[cur.box][cur.y][cur.x] + 1;
				q.push({ cur.box, ny, nx });
			}
		}

		// 앞, 뒤
		for (int k = cur.box - 1; k <= cur.box + 1; k++) {
			if (k < 0 || k >= h || k == cur.box) continue;
			// 익지 않은 토마토가 있으면
			if (tomato[k][cur.y][cur.x] == 0) {
				tomato[k][cur.y][cur.x] = tomato[cur.box][cur.y][cur.x] + 1;
				q.push({ k, cur.y, cur.x });
			}
		}
	}

	if (!is_ripen()) printf("-1\n");
	else printf("%d\n", answer - 1);
	return 0;
}
