// 1941_소문난_칠공주.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char board[5][5];
bool check[25] = { false, }; // 7개 선택 조합
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int answer = 0; // 경우의 수

// 인접 여부를 확인하기 위한 배열
void bfs() {
	bool visited[5][5] = { false, };
	queue<pair<int, int>> q;
	// 선택한 7명 중 1명 골라 큐에 push
	for (int i = 0; i < 25; i++) {
		if (check[i]) {
			q.push({ i / 5, i % 5 });
			visited[i / 5][i % 5] = true;
			break;
		}
	}

	int cnt = 1; // 선택한 사람 수
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		// 7명 모두 방문했다면 조건 만족
		if (cnt == 7) {
			answer++;
			break;
		}

		// 다음 정점 탐색
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 범위 벗어나면 패스
			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
			if (visited[ny][nx]) continue; // 이미 방문했으면 패스
			if (!check[ny * 5 + nx]) continue; // 조합에 포함되지 않으면 패스
			// 방문 후 큐에 push
			visited[ny][nx] = true; 
			q.push({ ny, nx });
			cnt++;	
		}
	}
}

// 25C7
// cur: 현재 위치, dasom: 이다솜파 수, cnt: 전체 수
void dfs(int cur, int dasom, int cnt) {
	// 7개를 모두 선택하면
	if (cnt == 7) {
		// 이다솜파가 4명 이상일 경우
		if (dasom >= 4) {
			bfs();
			return;
		}
	}

	for (int i = cur; i < 25; i++) {
		// 이미 선택된 사람이면 패스
		if (check[i]) continue;
		check[i] = true;
		// 선택한 사람이 이다솜파이면 +1
		if (board[i / 5][i % 5] == 'S') dasom++;
		dfs(i + 1, dasom, cnt + 1); // 다음 탐색
		// 백트래킹
		if (board[i / 5][i % 5] == 'S') dasom--;
		check[i] = false;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	// 탐색
	dfs(0, 0, 0);
	printf("%d\n", answer);
	return 0;
}
