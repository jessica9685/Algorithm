// 1525_퍼즐.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs(string start) {
	queue<pair<int, string>> q;
	set<string> visited; // 방문표시
	visited.insert(start);
	q.push({ 0, start });

	while (!q.empty()) {
		int cnt = q.front().first;
		string state = q.front().second;
		q.pop();

		// 목표 상태에 도달하면 종료
		if (state == "123456780") return cnt;

		// 0의 위치 파악
		int zero = state.find('0');
		int y = zero / 3;
		int x = zero % 3;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3) continue;
			
			// 빈칸과 숫자 위치 변경
			string next = state;
			swap(next[3 * y + x], next[3 * ny + nx]);
			// 아직 방문하지 않았으면
			if (visited.count(next) == 0) {
				visited.insert(next); // 방문표시
				q.push({ cnt + 1, next });
			}
		}
	}

	return -1;
}

int main() {
	string board = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char num;
			scanf(" %c", &num);
			board += num;
		}
	}

	int answer = bfs(board);
	printf("%d\n", answer);
	return 0;
}
