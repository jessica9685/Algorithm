// 18809_Gaaaaaaaaaarden.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int n, m; 
// 0: 호수, 1: 배양액 못뿌림
// 2: 배양액 뿌림, 3: green, 4: red
int garden[MAX][MAX]; 
int answer;
vector<pair<int, int>> yellow; // 배양액을 뿌릴 수 있는 땅
int gtime[MAX][MAX]; // (초록) 배양액 뿌린 시간
int rtime[MAX][MAX]; 
bool flower[MAX][MAX]; // 꽃이 핀 위치
int G, R;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs() {
	memset(gtime, -1, sizeof(gtime));
	memset(rtime, -1, sizeof(rtime));
	memset(flower, false, sizeof(flower));

	queue<pair<int, int>> green;
	queue<pair<int, int>> red;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (garden[i][j] == 3) {
				green.push({ i, j });
				gtime[i][j] = 0;
			}
			else if (garden[i][j] == 4) {
				red.push({ i, j });
				rtime[i][j] = 0;
			}
		}
	}

	int flowerCnt = 0;
	// 매 초마다 bfs 진행
	while (!green.empty() || !red.empty()) {
		int gsize = green.size();
		int rsize = red.size();

		// 초록색부터 뿌리기 
		while (gsize--) {
			int y = green.front().first;
			int x = green.front().second;
			green.pop();

			// 꽃이 핀 자리이면 패스
			if (flower[y][x]) continue;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				// 범위 벗어나면 패스
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				// 이미 배양액이 있으면 패스
				if (gtime[ny][nx] != -1 || rtime[ny][nx] != -1) continue;
				// 호수이면 패스
				if (garden[ny][nx] == 0) continue;

				gtime[ny][nx] = gtime[y][x] + 1;
				green.push({ ny, nx });
			}
		}

		// 빨간색 뿌리기
		while (rsize--) {
			int y = red.front().first;
			int x = red.front().second;
			red.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				// 범위 벗어나면 패스
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				// 이미 방문한 곳이면 패스
				if (rtime[ny][nx] != -1) continue;
				// 호수면 패스
				if (garden[ny][nx] == 0) continue;

				// 초록색 배양액이 없으면
				if (gtime[ny][nx] == -1) {
					rtime[ny][nx] = rtime[y][x] + 1;
					red.push({ ny, nx });
				}
				// 빨간 배양액과 초록 배양액이 겹치면 꽃 피움
				else if (rtime[y][x] + 1 == gtime[ny][nx]) {
					flower[ny][nx] = true;
					rtime[ny][nx] = rtime[y][x] + 1;
					flowerCnt++;
				}
			}
		}
	}
	
	if (answer < flowerCnt) answer = flowerCnt;
}

void dfs(int idx, int g, int r) {
	// 남은 배양액 개수가 땅보다 많으면 종료
	if (g + r > (yellow.size() - idx)) return;

	// 배양액을 모두 쓴 경우
	if (g == 0 && r == 0) {
		bfs();
		return;
	}

	if (idx == yellow.size()) return;

	int y = yellow[idx].first;
	int x = yellow[idx].second;

	// idx번째 땅에 배양액 안뿌리는 경우
	dfs(idx + 1, g, r);

	// 초록색 뿌리는 경우
	if (g > 0) {
		garden[y][x] = 3;
		dfs(idx + 1, g - 1, r);
		garden[y][x] = 2;
	}
	// 빨간색 뿌리는 경우
	if (r > 0) {
		garden[y][x] = 4;
		dfs(idx + 1, g, r - 1);
		garden[y][x] = 2;
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &G, &R);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &garden[i][j]);
			// 배양액을 뿌릴 수 있는 땅만 저장
			if (garden[i][j] == 2) yellow.push_back({ i, j });
		}
	}

	answer = 0;
	dfs(0, G, R);
	printf("%d\n", answer);
	return 0;
}
