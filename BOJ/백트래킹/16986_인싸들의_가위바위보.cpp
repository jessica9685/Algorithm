// 16986_인싸들의_가위바위보.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, k;
int table[10][10];

bool isWin = false; // 지우가 우승하면 true
int win[3] = { 0, 0, 0 }; // 지우, 경희, 민호 이긴 횟수
int turn[3] = { 0, 0, 0 }; // 지우, 경희, 민호의 turn index
int hand[3][20]; // 지우, 경희, 민호가 각 경기마다 낸 손동작

// 지우가 해당 손동작을 이미 사용했으면 true
bool check(int h) {
	for (int i = 0; i < turn[0]; i++) {
		if (hand[0][i] == h) return true;
	}
	return false;
}

// p1, p2: 플레이어 (0: 지우, 1: 경희, 2: 민호)
void dfs(int p1, int p2) {
	// 경희, 민호가 우승했을 때
	if (win[1] == k || win[2] == k) return;

	// 지우가 우승했을 때
	if (win[0] == k) {
		isWin = true;
		return;
	}

	for (int i = 1; i <= n; i++) {
		// 지우 차례가 아니면 반복문 1번만 수행
		if (p1 != 0 && p2 != 0) i = n;
		else {
			// 해당 손동작 방문 여부 확인
			if (check(i)) continue;
			hand[0][turn[0]] = i;
		}

		int res = table[hand[p1][turn[p1]]][hand[p2][turn[p2]]];
		int winner;

		if (res == 2) winner = p1;
		else if (res == 1) {
			if (p1 > p2) winner = p1;
			else winner = p2;
		}
		else winner = p2;

		// 인덱스 증가
		turn[p1]++;
		turn[p2]++;
		win[winner]++;
		dfs(winner, 3 - p1 - p2); // 다음 경기 진행
		// 백트래킹
		turn[p1]--;
		turn[p2]--;
		win[winner]--;
	}

	return;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int res;
			scanf("%d", &res);
			table[i][j] = res;
		}
	}

	// 경희
	for (int i = 0; i < 20; i++) scanf("%d", &hand[1][i]);
	// 민호
	for (int i = 0; i < 20; i++) scanf("%d", &hand[2][i]);

	dfs(0, 1);

	if (isWin) printf("1\n");
	else printf("0\n");
	return 0;
}
