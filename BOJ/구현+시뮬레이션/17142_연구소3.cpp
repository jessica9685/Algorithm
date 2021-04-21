// 17142_연구소3.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int n, m;
int lab[MAX][MAX];
int copied[MAX][MAX];
int visited[MAX][MAX];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<pair<int, int>> virus;

int main() {
	scanf("%d %d", &n, &m);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			if (num == 1) lab[i][j] = -1; // 벽: -1
			else if (num == 2) { // 바이러스: -2
				lab[i][j] = -2;
				virus.push_back({ i, j });
			}
			else {
				lab[i][j] = -3; // 빈칸: -3
				cnt++;
			}
		}
	}

	// 빈칸이 없으면 0 반환
	if (cnt == 0) {
		printf("0\n");
		return 0;
	}

	vector<int> active;
	for (int i = 0; i < m; i++) active.push_back(1);
	for (int i = 0; i < virus.size() - m; i++) active.push_back(0);

	sort(active.begin(), active.end());

	vector<int> time;

	do {
		memcpy(copied, lab, sizeof(lab));
		memset(visited, 0, sizeof(visited));
		queue<pair<int, pair<int, int>>> q;
		for (int i = 0; i < active.size(); i++) {
			if (active[i] == 1) {
				copied[virus[i].first][virus[i].second] = 0;
				q.push({ 0, {virus[i].first, virus[i].second} });
				visited[virus[i].first][virus[i].second] = 1;
			}
		}

		while (!q.empty()) {
			int sec = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				// 범위 밖
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				// 벽이거나 이미 방문한 곳
				if (copied[nx][ny] == -1 || visited[nx][ny] == 1) continue;
				/* 
					바이러스를 퍼트릴 때는 빈칸/비활성 상관 없이 일단 퍼트리고, 
					후에 시간 계산할 때 비활성 바이러스가 있는 칸의 시간은 고려 X 
				*/
				// 빈칸이거나 비활성 바이러스가 있는 곳
				if (copied[nx][ny] == -3 || copied[nx][ny] == -2) { 
					copied[nx][ny] = sec + 1;
					visited[nx][ny] = 1;
					q.push({ copied[nx][ny], {nx, ny} });
				}
			}
		}

		int cnt = 0; // 빈칸 개수
		int res = 0; // 바이러스 퍼지는데 걸린 시간
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (copied[i][j] == -3) cnt++;
				// 해당 칸의 시간이 res보다 크고
				// 해당 칸에 비활성 바이러스가 없으면
				else if (copied[i][j] > res && lab[i][j] != -2) {
					res = copied[i][j]; // res 업데이트
				}
			}
		}
		
		if (cnt == 0) time.push_back(res);
	} while (next_permutation(active.begin(), active.end()));

	sort(time.begin(), time.end());

	if (time.empty()) printf("-1\n");
	else printf("%d\n", *time.begin());
	return 0;
}
