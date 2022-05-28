// 3109_빵집.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int r, c;
int dy[3] = { -1, 0, 1 };
int dx[3] = { 1, 1, 1 };
char board[10000][500];
bool visited[10000][500];
int answer = 0;
bool isExist = false; // 파이프라인 경로가 존재하면 true

void dfs(int y, int x) {
	visited[y][x] = true;

	if (x == c - 1) {
		isExist = true;
		answer++;
		return;
	}

	for (int d = 0; d < 3; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (visited[ny][nx] || board[ny][nx] == 'x') continue;

		dfs(ny, nx);
		if (isExist) return; // 이미 경로를 찾았으면 종료
	}
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}

	for (int y = 0; y < r; y++) {
		isExist = false;
		dfs(y, 0);
	}
	printf("%d\n", answer);
	return 0;
}
