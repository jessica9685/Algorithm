// 1079_마피아.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 16

int n; // 0부터 시작
// 죽은 사람의 유죄지수는 0
int guilty[MAX]; // 유죄지수 
int crime[MAX][MAX]; // R 배열
bool visited[MAX];
int mafia; // 마피아 번호
int answer;

// alive: 남은 인원 수, cnt: 지낸 밤의 횟수, night: 낮/밤, idx: 유죄지수 최대인 참가자
void dfs(int alive, int cnt, int night, int idx) {
	// 1명 남았으면
	if (alive == 1) {
		answer = max(answer, cnt);
		return;
	}

	// 낮일 때 (홀수)
	if (night) {
		if (idx == mafia) {
			answer = max(answer, cnt);
			return;
		}
		visited[idx] = true;
		dfs(alive - 1, cnt, 0, -1);
		visited[idx] = false;
	}
	// 밤일 때 (짝수)
	else {
		for (int i = 0; i < n; i++) {
			// 이미 죽었거나 마피아면 pass
			if (visited[i] || i == mafia) continue;
			
			/* 죽이기 */
			visited[i] = true;
			// 유죄지수 계산
			int maxIdx = 0; // 최대 유죄지수를 가진 사람
			int maxCrime = 0; // 최대 유죄지수
			for (int j = 0; j < n; j++) {
				if (visited[j]) continue;
				guilty[j] += crime[i][j];
				
				if (maxCrime < guilty[j]) {
					maxCrime = guilty[j];
					maxIdx = j;
				}
			}

			// 다음 dfs 진행
			dfs(alive - 1, cnt + 1, 1, maxIdx);

			/* 되돌리기 */
			for (int j = 0; j < n; j++) {
				if (visited[j]) continue;
				guilty[j] -= crime[i][j];
			}
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);

	int maxCrime = 0; // 최대 유죄지수
	int maxIdx = 0; // 유죄지수가 최대인 사람
	// 각 참가자의 유죄 지수 입력
	for (int i = 0; i < n; i++) {
		scanf("%d", &guilty[i]);
		if (maxCrime < guilty[i]) {
			maxCrime = guilty[i];
			maxIdx = i;
		}
	}

	// R 배열 (유죄지수 계산)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &crime[i][j]);
		}
	}

	scanf("%d", &mafia);

	answer = 0;
	dfs(n, 0, n % 2, maxIdx);

	printf("%d\n", answer);
	return 0;
}
