// 16197_두_동전.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

// 두 동전의 위치
typedef struct Coin {
	int y1, x1;
	int y2, x2;
};

int n, m;
char board[20][20];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int answer = 100;

// 보드 밖을 나가면 true
bool board_out(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) return true;
	else return false;
}

void dfs(int cnt, Coin coin) {
	// 버튼을 10번 넘게 누르면 종료
	if (cnt > 10) return;
	if (board_out(coin.y1, coin.x1) || board_out(coin.y2, coin.x2)) {
		// 동전 두개 다 떨어지면 종료
		if (board_out(coin.y1, coin.x1) && board_out(coin.y2, coin.x2)) return;
		else {
			// 최소값 갱신
			answer = min(answer, cnt);
			return;
		}
	}

	for (int d = 0; d < 4; d++) {
		int ny1 = coin.y1 + dy[d];
		int nx1 = coin.x1 + dx[d];
		int ny2 = coin.y2 + dy[d];
		int nx2 = coin.x2 + dx[d];

		// 둘 중 하나라도 떨어지면 다음으로
		if (board_out(ny1, nx1) || board_out(ny2, nx2)) {
			dfs(cnt + 1, { ny1, nx1, ny2, nx2 });
		}
		else {
			// 벽이면 이동하지 않고 다음으로
			if (board[ny1][nx1] == '#') {
				ny1 = coin.y1;
				nx1 = coin.x1;
			}
			if (board[ny2][nx2] == '#') {
				ny2 = coin.y2;
				nx2 = coin.x2;
			}
			dfs(cnt + 1, { ny1, nx1, ny2, nx2 });
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	vector<pair<int, int>> coin;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'o') {
				coin.push_back({ i, j });
				board[i][j] = '.';
			}
		}
	}
	
	Coin c;
	c.y1 = coin[0].first, c.x1 = coin[0].second;
	c.y2 = coin[1].first, c.x2 = coin[1].second;
	dfs(0, c);

	if (answer == 100) answer = -1;
	printf("%d\n", answer);
	return 0;
}
