// 2151_거울_설치.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define INF 987654321

typedef struct pos {
	int y;
	int x;
	int dir;
};

int n;
char home[MAX][MAX];
// 각 좌표의 상/하/좌/우 방문 정보
// 빛 반사가 몇번 이루어졌는지 저장
int visited[MAX][MAX][4];
int dy[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
int dx[4] = { 0, 0, -1, 1 };

vector<pair<int, int>> door; // 문 2개
queue<pos> q; // bfs 큐


// 거울을 만났을 때 바뀔 수 있는 방향 2가지를 리턴
pair<int, int> reflectDir(int curD) {
	// 상, 하 -> 좌, 우로 반사
	if (curD < 2) return make_pair(2, 3);
	// 좌, 우 -> 상, 하로 반사
	else return make_pair(0, 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &home[i][j]);

			if (home[i][j] == '#') { // 문 표시
				door.push_back({ i, j });
			}

			for (int k = 0; k < 4; k++) { // visited 초기화
				visited[i][j][k] = INF;
			}
		}
	}

	// 시작점(문)부터 모든 방향에 대해 탐색
	for (int i = 0; i < 4; i++) {
		q.push({ door[0].first, door[0].second, i });
		visited[door[0].first][door[0].second][i] = 0;
	}

	// bfs
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();

		int ny = y + dy[dir];
		int nx = x + dx[dir];
		pair<int, int> nDir = reflectDir(dir);

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue; // 범위 벗어남
		if (home[ny][nx] == '*') continue; // 벽
		if (home[ny][nx] == '!') { // 거울을 놓을 수 있는 곳이면
			// 거울 설치 X
			if (visited[ny][nx][dir] > visited[y][x][dir]) {
				visited[ny][nx][dir] = visited[y][x][dir];
				q.push({ ny, nx, dir });
			}
			// 거울 설치 1 (첫 번째 방향)
			if (visited[ny][nx][nDir.first] > visited[y][x][dir] + 1) {
				visited[ny][nx][nDir.first] = visited[y][x][dir] + 1;
				q.push({ ny, nx, nDir.first });
			}
			// 거울 설치 2 (두 번째 방향)
			if (visited[ny][nx][nDir.second] > visited[y][x][dir] + 1) {
				visited[ny][nx][nDir.second] = visited[y][x][dir] + 1;
				q.push({ ny, nx, nDir.second });
			}
		}
		else if (home[ny][nx] == '.') { // 아무것도 없으면
			// 거울 설치 X
			if (visited[ny][nx][dir] > visited[y][x][dir]) {
				visited[ny][nx][dir] = visited[y][x][dir];
				q.push({ ny, nx, dir });
			}
		}
		else if (home[ny][nx] == '#') { // 문이면
			// 거울 설치 X + 큐에 넣지 X
			if (visited[ny][nx][dir] > visited[y][x][dir]) {
				visited[ny][nx][dir] = visited[y][x][dir];
			}
		}
	}

	// 빛반사가 최소가 되는 방향을(거울 개수 최소) 구하기
	int answer = INF;
	for (int i = 0; i < 4; i++) {
		answer = min(answer, visited[door[1].first][door[1].second][i]);
	}

	printf("%d\n", answer);
	return 0;
}
