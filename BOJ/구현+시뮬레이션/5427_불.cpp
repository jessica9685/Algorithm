// 5427_불.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int w, h;
char maps[MAX][MAX];
int fireTime[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
bool isExit = false;

// 불이 퍼지는 시간 저장
void fire_bfs(queue<pair<int, int>> q) {
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (fireTime[ny][nx] == 0 && maps[ny][nx] == '.') {
				fireTime[ny][nx] = fireTime[cur.first][cur.second] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

// 각 지점 도착 시간 저장
void exitBuilding(pair<int, int> start) {	
	queue<pair<int, int>> q;
	q.push(start);

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		// 탈출 가능한지?
		if (cur.first == 0 || cur.first == h - 1 || cur.second == 0 || cur.second == w - 1) {
			printf("%d\n", visited[cur.first][cur.second] + 1);
			isExit = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			// 이미 방문했거나, 벽이거나, 불이 있으면 pass
			if (visited[ny][nx] > 0 || maps[ny][nx] == '#' || maps[ny][nx] == '*') continue;
			if (maps[ny][nx] == '.') {
				// 아직 불이 없는 곳이면 진행
				// 해당 위치가 .이고 fireTime이 0이면 불이 퍼질 수 없는 곳
				if (fireTime[ny][nx] == 0 || fireTime[ny][nx] > visited[cur.first][cur.second] + 1) {
					visited[ny][nx] = visited[cur.first][cur.second] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &w, &h); 
		
		pair<int, int> start;
		queue<pair<int, int>> fireQ;
		// 이외 변수 초기화
		memset(fireTime, 0, sizeof(fireTime));
		memset(visited, 0, sizeof(visited));
		isExit = false;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %1c", &maps[i][j]);
				if (maps[i][j] == '@') {
					start = make_pair(i, j);
					maps[i][j] = '.';
				}
				if (maps[i][j] == '*') {
					fireQ.push({ i, j });
				}
			}
		}

		// 불 번짐
		if(!fireQ.empty()) fire_bfs(fireQ);
		// 이동
		exitBuilding(start);

		if (!isExit) printf("IMPOSSIBLE\n");
	}
}
