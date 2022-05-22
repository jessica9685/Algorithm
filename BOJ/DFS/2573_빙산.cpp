// 2573_빙산.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
#define MAX 300

int n, m;
int ice[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// 얼음 녹이기
void melt() {
	int copied[MAX][MAX];
	memcpy(copied, ice, sizeof(ice));

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (ice[y][x] == 0) continue;

			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (ice[ny][nx] == 0) cnt++;
			}

			if (cnt > 0) copied[y][x] -= cnt;
			if (copied[y][x] < 0) copied[y][x] = 0;
		}
	}

	memcpy(ice, copied, sizeof(copied));
}

// 덩어리 확인
void dfs(int y, int x) {
	visited[y][x] = true;

	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (ice[ny][nx] != 0 && !visited[ny][nx]) dfs(ny, nx);
	}

	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ice[i][j]);
		}
	}

	int year = 0;
	while (true) {
		melt();
		year++;

		memset(visited, false, sizeof(visited));
		int cnt = 0; // 덩어리 개수
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (ice[y][x] == 0 || visited[y][x]) continue;
				dfs(y, x);
				cnt++;
			}
		}

		if (cnt > 1) { // 덩어리가 2개 이상이면
			printf("%d\n", year);
			break;
		}
		else if (cnt == 0) { // 얼음이 다 녹아버리면
			printf("0\n");
			break;
		}
	}
	return 0;
}
