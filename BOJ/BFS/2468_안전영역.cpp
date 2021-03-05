// 2468_안전영역.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n;
int area[MAX][MAX];
int copied[MAX][MAX];
int visited[MAX][MAX];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void bfs(int a, int b) {
	visited[a][b] = 1;
	queue<pair<int, int>> q;
	q.push({ a, b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!visited[nx][ny] && area[nx][ny] != -1) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
			maxi = max(maxi, area[i][j]);
		}
	}

	int answer = 0;
	memcpy(copied, area, sizeof(area));
	// h가 0인 경우(아무 지역도 물에 잠기지 않은 경우) 고려
	for (int h = 0; h <= maxi; h++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (area[i][j] <= h) area[i][j] = -1;
			}
		}

		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (area[i][j] != -1 && !visited[i][j]) {
					bfs(i, j);
					cnt += 1;
				}
			}
		}

		answer = max(answer, cnt);
		memcpy(area, copied, sizeof(copied));
	}

	cout << answer << endl;
}
