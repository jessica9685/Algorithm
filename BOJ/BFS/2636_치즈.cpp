// 2636_치즈.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int n, m;
int cheeze[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// 치즈 주변 공기 check
void bfs(int y, int x) {
	// visited 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) visited[i][j] = false;
	}

	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ y, x });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			// 범위 벗어나면 pass
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			// 이미 방문했거나 치즈이면 pass
			if (visited[ny][nx] || cheeze[ny][nx] == 1) continue;
			
			visited[ny][nx] = true;
			cheeze[ny][nx] = 2; // 주변 공기 2로 check 
			q.push({ ny, nx });
		}
	}
}

// 주변 칸 중 하나라도 2가 있으면 (주변공기가 존재하면) 녹음
bool isMelt(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (cheeze[ny][nx] == 2) return true;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	int last = 0; // 녹기 1시간 전에 남아있는 치즈
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &cheeze[i][j]);
			if (cheeze[i][j] == 1) last++;
		}
	}

	int hour = 0; // 다 녹는데 걸린 시간
	while (true) {
		// 주변 공기 check
		bfs(0, 0);

		hour++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 치즈 녹이기
				if (cheeze[i][j] == 1 && isMelt(i, j)) {
					cheeze[i][j] = 0;
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cheeze[i][j] == 1) sum++;
			}
		}

		if (sum == 0) break;
		else last = sum;
	}

	printf("%d\n", hour);
	printf("%d\n", last);
	return 0;
}
