// 17825_주사위_윷놀이.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int board[35]; // 윷놀이 판 순서
// board[i] = j : i의 다음 칸이 j
int score[35]; // 각 판의 점수
int turn[35]; // 방향 전환 (10, 20, 25, 30)
int dice[10]; // 주사위
bool visited[35]; // 말이 있으면 true
int horse[4];
int ans = 0;

void dfs(int idx, int sum) {
	// 10번 다 이동하면
	if (idx == 10) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int cur = horse[i]; // 현재 말 위치
		int next = cur; // 이동 후 위치
		int move = dice[idx];

		// 방향 전환이 필요한 위치에 있으면
		if (turn[next] > 0) {
			// 방향 전환 후 이동
			next = turn[next];
			move--;
		}

		// 주사위 숫자만큼 이동
		while (move--) next = board[next];

		// 도착점이 아니고 해당 위치에 말이 있으면 패스
		if (next != 21 && visited[next]) continue;
		
		// 방문표시 후 이동
		visited[cur] = false;
		visited[next] = true;
		horse[i] = next;
		
		dfs(idx + 1, sum + score[next]);
		
		// 백트래킹
		visited[cur] = true;
		visited[next] = false;
		horse[i] = cur;
	}
}

int main() {
	// 윷놀이 판 초기화
	for (int i = 0; i <= 20; i++) board[i] = i + 1;
	board[21] = 21; // 도착하면 더이상 움직이지 않음
	for (int i = 22; i < 27; i++) board[i] = i + 1;
	board[27] = 20; board[28] = 29; board[29] = 30; 
	board[30] = 25; board[31] = 32; board[32] = 25;

	turn[5] = 22; turn[10] = 31; turn[15] = 28; turn[25] = 26;

	// 점수판
	for (int i = 0; i <= 20; i++) score[i] = i * 2;
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[25] = 25; score[26] = 30; score[27] = 35;
	score[28] = 28; score[29] = 27; score[30] = 26;
	score[31] = 22; score[32] = 24;

	for (int i = 0; i < 10; i++) scanf("%d", &dice[i]);

	dfs(0, 0);

	printf("%d\n", ans);
	return 0;
}
