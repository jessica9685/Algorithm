// 2638_치즈.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n, m;
int cheeze[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// 주변 공기 check
void airCheck(pair<int, int> start) {
	// visited 초기화
	memset(visited, false, sizeof(visited));

	visited[start.first][start.second] = true;
	queue<pair<int, int>> q;
	q.push(start);

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 범위 벗어나면 pass
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			// 아직 방문 x, 치즈가 아니면
			if (!visited[ny][nx] && cheeze[ny][nx] != 1) {
				visited[ny][nx] = true;
				cheeze[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
	}
}

bool isMelt(int y, int x) {
	int cnt = 0; // 공기와 맞닿은 부분
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (cheeze[ny][nx] == 2) cnt++;
	}

	if (cnt >= 2) return true;
	else return false;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &cheeze[i][j]);
		}
	}

	int answer = 0;
	while (true) {
		// 주변 공기 check
		airCheck({ 0, 0 });

		queue<pair<int, int>> melted;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 녹는 치즈는 큐에 push
				if (cheeze[i][j] == 1 && isMelt(i, j)) {
					melted.push({ i, j });
				}
			}
		}

		// 치즈가 다 안녹았으면
		if (!melted.empty()) { 
			answer++; // 시간 증가
			// 치즈 녹이기
			while (!melted.empty()) {
				int y = melted.front().first;
				int x = melted.front().second;
				melted.pop();
				cheeze[y][x] = 0;
			}
		}
		else break;
	}

	printf("%d\n", answer);
}
