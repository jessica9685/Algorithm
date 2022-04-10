// 16235_나무_재테크.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 11

int n, m, k;
int land[MAX][MAX]; // 양분
int a[MAX][MAX];
vector<int> tree[MAX][MAX]; // 나무
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// 봄 & 여름
void spring_summer() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (tree[y][x].empty()) continue;
				
			// 같은 위치에 나무가 여러개면 어린 나무부터
			if (tree[y][x].size() > 1) sort(tree[y][x].begin(), tree[y][x].end());
			for (int i = 0; i < tree[y][x].size(); i++) {
				// 봄
				if (land[y][x] >= tree[y][x][i]) {
					land[y][x] -= tree[y][x][i]; // 나이만큼 양분 먹고
					tree[y][x][i]++; // 나이 1 증가
				}
				// 여름
				else {
					// 현재 나무보다 나이 많은 모든 나무가 죽고 양분이 됨
					int s = tree[y][x].size();
					for (int j = s - 1; j >= i; j--) {
						land[y][x] += (tree[y][x][j] / 2);
						tree[y][x].pop_back();
					}
					break;
				}
			}
		}
	}
}

// 가을
void autumn() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (tree[y][x].empty()) continue;
			for (int t = 0; t < tree[y][x].size(); t++) {
				// 나이가 5의 배수이면
				if (tree[y][x][t] % 5 == 0) {
					// 인접한 칸에 나무 번식
					for (int i = 0; i < 8; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];

						if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

// 겨울
void winter() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			land[y][x] += a[y][x];
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			land[i][j] = 5; // 초기 양분은 5
		}
	}
	for (int i = 0; i < m; i++) {
		int y, x, z;
		scanf("%d %d %d", &y, &x, &z);
		tree[y][x].push_back(z);
	}

	while (k--) {
		spring_summer();
		autumn();
		winter();
	}

	int ans = 0;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (!tree[y][x].empty()) {
				ans += tree[y][x].size();
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
