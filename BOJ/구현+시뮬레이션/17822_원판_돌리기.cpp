// 17822_원판_돌리기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int n, m, T;
int circle[MAX][MAX];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void rotate(int num, int d, int k) {
	// num번째 원판 복사
	int copied[MAX];
	for (int i = 1; i <= m; i++) copied[i] = circle[num][i];

	for (int i = 1; i <= m; i++) {
		int moved = (i + k) % m;
		if (moved == 0) moved = m;

		// 시계 방향
		if (d == 0) circle[num][moved] = copied[i];
		// 반시계 방향
		else circle[num][i] = copied[moved];
	}
}

void adj() {
	bool check[MAX][MAX] = { false, };
	bool isExist = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] || circle[i][j] == 0) continue;

			for (int d = 0; d < 4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				// 원판의 범위를 벗어나면 패스
				if (ny > n || ny < 1) continue;

				// 원판 내부 번호가 범위를 넘어가면 조정
				if (nx < 1) nx = m;
				else if (nx > m) nx = 1;

				// 인접한 두 수가 같으면 check
				if (circle[i][j] == circle[ny][nx]) {
					check[i][j] = true;
					check[ny][nx] = true;
					isExist = true;
				}
			}
		}
	}

	// 2-1. 인접한 수 제거
	if (isExist) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (check[i][j]) circle[i][j] = 0;
			}
		}
	}
	// 2-2. 인접한 수가 없는 경우
	else {
		int sum = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (circle[i][j] != 0) {
					sum += circle[i][j];
					cnt++;
				}
			}
		}

		double avg = (double)sum / (double)cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (circle[i][j] != 0) {
					if (circle[i][j] < avg) circle[i][j]++;
					else if(circle[i][j] > avg) circle[i][j]--;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &T);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &circle[i][j]);
		}
	}
	while (T--) {
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);

		// 1. x의 배수인 원판 회전
		for (int i = 1; i <= n / x; i++) {
			int num = x * i;
			rotate(num, d, k);
		}

		// 2. 인접한 같은 수 찾기
		adj();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (circle[i][j] != 0) ans += circle[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}
