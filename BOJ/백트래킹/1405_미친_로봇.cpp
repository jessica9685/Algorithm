// 1405_미친_로봇.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
double pmove[4]; // 동(오), 서(왼), 남(아래), 북(위) 확률
bool board[50][50];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
double answer;

void dfs(int y, int x, int cnt, double p) {
	if (cnt == n) {
		answer += p;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 이미 방문한 곳을 다시 가면 단순 X
		if (board[ny][nx]) continue;
		board[ny][nx] = true;
		dfs(ny, nx, cnt + 1, p * pmove[i]);
		board[ny][nx] = false;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		int x;
		scanf("%d", &x);
		pmove[i] = (double)x / (double)100;
	}

	board[25][25] = true;
	answer = 0;
	dfs(25, 25, 0, 1);
	
	printf("%.9f\n", answer);
	return 0;
}
