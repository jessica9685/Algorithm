// 1103_게임.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[51][51];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// (y, x)에서 이동할 수 있는 최대 횟수
int dp[51][51];
// 사이클 판단용 방문 표시
bool visited[51][51];

int dfs(int y, int x) {
	// 구멍이거나 보드 바깥이면 종료
	if (board[y][x] == 0 || y < 0 || x < 0 || y >= N || x >= M) return 0;

	// 이미 방문한 곳을 다시 방문한 경우 -> 사이클 존재
	if (visited[y][x]) {
		printf("-1\n");
		exit(0);
	}

	// dp가 초기값이 아닌 경우
	if (dp[y][x] != -1) return dp[y][x];

	// 현재 정점 방문
	visited[y][x] = true;
	dp[y][x] = 0;
	// 다음 정점 방문
	for (int i = 0; i < 4; i++) {
		int ny = y + board[y][x] * dy[i];
		int nx = x + board[y][x] * dx[i];
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}

	// 되돌아가기
	visited[y][x] = false;
	return dp[y][x];
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			scanf(" %1c", &c);
			if (c == 'H') board[i][j] = 0;
			else board[i][j] = c - '0';

			// 변수 초기화
			visited[i][j] = false;
			dp[i][j] = -1;
		}
	}

	// 구해야하는 값 = dp[0][0]
	int ans = dfs(0, 0);
	printf("%d\n", ans);

	return 0;
}
