// 21610_마법사_상어와_비바라기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int n, m;
int basket[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q; // 구름 위치
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

// 1. 모든 구름이 di 방향으로 si칸 이동한다.
// 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
// 3. 구름이 모두 사라진다
void move_cloud(int d, int s) {
	int size = q.size();
	for(int i = 0; i < size; i++) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		// 1. 구름 이동
		int ny = y, nx = x;
		for(int i = 0; i < s; i++) {
			ny += dy[d];
			nx += dx[d];
			
			if (ny < 1) ny = n;
			else if (ny > n) ny = 1;
				
			if (nx < 1) nx = n;
			else if (nx > n) nx = 1;
		}

		basket[ny][nx]++; // 2. 빗물 증가
		visited[ny][nx] = true; // 3. 구름이 이동한 후 사라진 위치 표시
		q.push({ ny, nx });
	}
}

// 4. 물 복사
void copy_water() {
	// 구름이 있던 자리의 대각선 방향의 바구니 탐색
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 2; d <= 8; d += 2) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			// 경계를 벗어나면 패스
			if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
			// 대각선 방향의 바구니에 물이 있으면 카운트
			if (basket[ny][nx] > 0) basket[y][x]++;
		}
	}
}

// 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
void create_cloud() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			// 3에서 구름이 사라진 칸이 아니고, 물의 양이 2 이상이면
			if (basket[y][x] >= 2 && !visited[y][x]) {
				q.push({ y, x });
				basket[y][x] -= 2;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	// 바구니
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &basket[i][j]);
		}
	}

	// 초기 구름
	q.push({ n, 1 });
	q.push({ n, 2 });
	q.push({ n - 1, 1 });
	q.push({ n - 1, 2 });

	while (m--) {
		int d, s;
		scanf("%d %d", &d, &s);

		// 초기화
		memset(visited, false, sizeof(visited));

		move_cloud(d, s);
		copy_water();
		create_cloud();
	}

	// 남은 물의 양의 합
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (basket[i][j] > 0) ans += basket[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}
