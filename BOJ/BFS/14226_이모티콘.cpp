// 14226_이모티콘.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int s; // 목표 개수
bool visited[MAX][MAX]; // 화면, 클립보드

int bfs() {
	// (화면, 클립보드), 시간
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 1, 0 }, 0 });
	visited[1][0] = true;

	while (!q.empty()) {
		int dis = q.front().first.first;
		int clip = q.front().first.second;
		int time = q.front().second;
		q.pop();

		// 목표 개수에 도달하면 return
		if (dis == s) return time;

		// 화면에 있는 이모티콘 개수가 범위 이내이면
		if (dis > 0 && dis < MAX) {
			// 1. 화면에 있는 이모티콘을 모두 복사해 클립보드에 저장
			if (!visited[dis][dis]) {
				visited[dis][dis] = true;
				q.push({ {dis, dis}, time + 1 });
			}

			// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
			if (clip > 0 && dis + clip < MAX) {
				if (!visited[dis + clip][clip]) {
					visited[dis + clip][clip] = true;
					q.push({ {dis + clip, clip}, time + 1 });
				}
			}

			// 3. 화면에 있는 이모티콘 중 하나 삭제
			if (!visited[dis - 1][clip]) {
				visited[dis - 1][clip] = true;
				q.push({ {dis - 1, clip}, time + 1 });
			}
		}
	}
}


int main() {
	scanf("%d", &s);
	printf("%d\n", bfs());
	return 0;
}
