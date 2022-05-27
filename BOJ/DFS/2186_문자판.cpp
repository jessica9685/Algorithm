// 2186_문자판.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
#define MAX 100

int n, m, K;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
char board[MAX][MAX]; // 문자판
string word; // 만들려는 단어
int word_len; // 단어 길이
// dp[y][x][idx] : (y, x)가 idx번째 문자일 때 word를 찾을 수 있는 경우의 수
// memoization
int dp[MAX][MAX][80]; 

int dfs(int y, int x, int idx) {
	// 이미 값이 존재하면 리턴
	if (dp[y][x][idx] != -1) return dp[y][x][idx];
	// 범위를 넘어가면 1 리턴
	if (idx >= word_len) return 1;

	dp[y][x][idx] = 0;
	for (int k = 1; k <= K; k++) {
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d] * k;
			int nx = x + dx[d] * k;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (board[ny][nx] != word[idx]) continue;

			dp[y][x][idx] += dfs(ny, nx, idx + 1);
		}
	}

	return dp[y][x][idx];
}

int main() {
	scanf("%d %d %d", &n, &m, &K);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> word;
	word_len = word.length();

	memset(dp, -1, sizeof(dp));
	int answer = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (board[y][x] == word[0]) {
				answer += dfs(y, x, 1);
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}
