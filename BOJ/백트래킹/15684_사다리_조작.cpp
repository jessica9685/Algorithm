// 15684_사다리_조작.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, h;
// ladder[세로선(n)][가로선(h)]
int ladder[11][31];
int answer = 1000;

// i번 세로선 출발 -> i번 도착이면 true
bool game_result() {
	// 각각의 세로선에 대해
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 1; j <= h; j++) {
			// 사다리가 존재하면 사다리 통해서 이동
			if (ladder[cur][j] == 1) cur++;
			else if (ladder[cur - 1][j] == 1) cur--;
		}
		if (cur != i) return false;
	}
	return true;
}

void draw_line(int row, int cnt) {
	// 추가한 선이 3보다 크면 종료
	if (cnt > 3) return;
	// 게임 조건을 만족하면 종료
	if (game_result()) {
		answer = min(answer, cnt);
		return;
	}

	for (int j = row; j <= h; j++) {
		for (int i = 1; i < n; i++) {
			// 가로선이 연속되거나 접하면 패스
			if (ladder[i][j] == 1 || ladder[i - 1][j] == 1 || ladder[i + 1][j] == 1) continue;
			ladder[i][j] = 1; // 선 긋기
			// 주의: j 위치에 사다리가 여러개 있을 수 있으므로 +1 하면 안됨
			// draw_line(j + 1, cnt + 1)할 경우 70%에서 틀림
			draw_line(j, cnt + 1);
			ladder[i][j] = 0; // 선 지우기
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		int a, b; // b: 세로선
		scanf("%d %d", &a, &b);
		ladder[b][a] = 1;
	}

	draw_line(1, 0);
	// 불가능하거나 3보다 크면 -1
	if (answer == 1000) answer = -1;
	printf("%d\n", answer);
	return 0;
}
