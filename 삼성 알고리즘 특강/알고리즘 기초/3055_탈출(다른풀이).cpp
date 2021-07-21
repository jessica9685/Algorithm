// 3055_탈출.cpp
// 큐를 1개만 사용하는 풀이
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 50

typedef struct Point {
	int y;
	int x;
	char type; // 물인지 고슴도치인지?
};

int r, c;
int dp[MAX][MAX]; // 방문한 시간을 기록
char forest[MAX][MAX]; // 지도
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

queue<Point> q;
bool foundAnswer = false;

void bfs(Point start) {
	// 시작점 큐에 삽입
	q.push(start);
	while (!q.empty()) {
		// 1. 큐에서 꺼내줌
		Point p = q.front();
		q.pop();

		// 2. 목적지인가?
		if (p.type == 'D') {
			printf("%d\n", dp[p.y][p.x]);
			foundAnswer = true;
			break;
		}

		// 3. 연결된(갈 수 있는) 곳을 순회
		for (int i = 0; i < 4; i++) {
			int ny = p.y + dir[i][0];
			int nx = p.x + dir[i][1];

			// 4. 갈 수 있는가?
			if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
				// 물인 경우
				if (p.type == '*') {
					// 비어있으면
					if (forest[ny][nx] == '.' || forest[ny][nx] == 'S') {
						// 5. 체크인
						forest[ny][nx] = '*';
						// 6. 큐에 넣음
						q.push({ ny, nx, '*' });
					}
				}
				// 고슴도치인 경우
				else {
					if (forest[ny][nx] == 'D' || forest[ny][nx] == '.') {
						// 아직 방문 안한 곳이면
						if (dp[ny][nx] == 0) {
							// 5. 체크인
							dp[ny][nx] = dp[p.y][p.x] + 1;
							// 6. 큐에 넣음
							q.push({ ny, nx, forest[ny][nx] });
						}
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &r, &c);

	Point start;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %c", &forest[i][j]);

			if (forest[i][j] == 'S') {
				start.y = i;
				start.x = j;
				start.type = 'S';
			}
			// 물인 경우 미리 큐에 삽입
			else if (forest[i][j] == '*') {
				q.push({ i, j, '*' });
			}
		}
	}

	bfs(start);
	if (!foundAnswer) printf("KAKTUS\n");
	return 0;
}
