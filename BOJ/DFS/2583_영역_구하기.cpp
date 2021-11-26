// 2583_영역_구하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int m, n, k;
int board[MAX][MAX];
bool visited[MAX][MAX] = { false, };
int cnt; // 분리된 영역의 넓이
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
vector<int> ans;

void dfs(int y, int x) {
	visited[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		// 아직 방문 안했고, 직사각형 아니면
		if (board[ny][nx] == 0 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++) {
		int y1, x1, y2, x2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		// 직사각형 표시
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				board[i][j] = 1;
				visited[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 직사각형이 아닌 부분이면
			if (board[i][j] == 0 && !visited[i][j]) {
				// 영역 넓이 계산
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}

	// 오름차순 정렬
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
