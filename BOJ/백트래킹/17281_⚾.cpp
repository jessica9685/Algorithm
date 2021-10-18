// 17281_⚾.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int n; // 이닝 수
int inning[MAX][9]; // 이닝 번호, 타자 번호
int answer = 0;
int seq[9];
bool visited[9] = { false, };

int calc_score(int seq[]) {
	int result = 0;
	int cur = 0; // 현재 타자 순서

	for (int i = 0; i < n; i++) {
		int out = 0; // 아웃 수
		
		// 각 루의 상태
		// 0: home
		bool base[4] = { false, };

		while (out < 3) {
			int play = inning[i][seq[cur]];

			// 0. 아웃
			if (play == 0) out++;
			// 1. 안타
			else if (play == 1) {
				// 3 ~ 1루 탐색
				for (int j = 3; j >= 1; j--) {
					// 주자가 있으면
					if (base[j]) {
						if (j == 3) { // 3루에 주자가 있으면
							result++; // 점수 추가
							base[j] = false;
						}
						else { // 1루씩 이동
							base[j + 1] = true;
							base[j] = false;
						}
					}
				}
				base[1] = true; // 타자는 1루 진출
			}
			// 2. 2루타
			else if (play == 2) {
				// 3 ~ 1루 탐색
				for (int j = 3; j >= 1; j--) {
					// 주자가 있으면
					if (base[j]) {
						if (j == 1) { // 1루에 주자가 있으면
							base[j + 2] = true;
							base[j] = false;
						}
						else { // 2, 3루는 점수 추가
							result++;
							base[j] = false;
						}
					}
				}
				base[2] = true; // 타자는 2루 진출
			}
			// 3. 3루타
			else if (play == 3) {
				// 3 ~ 1루 탐색
				for (int j = 3; j >= 1; j--) {
					// 주자가 있으면
					if (base[j]) {
						result++;
						base[j] = false;
					}
				}
				base[3] = true; // 타자는 3루 진출
			}
			// 4. 홈런
			else if (play == 4) {
				// 3 ~ 1루 탐색
				for (int j = 3; j >= 1; j--) {
					// 주자가 있으면
					if (base[j]) {
						result++;
						base[j] = false;
					}
				}
				result++; // 타자 점수 추가
			}
			// 다음 타자
			cur = (cur + 1) % 9;
		}
	}

	return result;
}

void dfs(int idx) {
	if (idx == 9) {
		int res = calc_score(seq);
		if (answer < res) answer = res;
		return;
	}

	// 4번 타자는 1로 고정이므로 넘어감
	if (idx == 3) dfs(idx + 1);

	for (int i = 1; i < 9; i++) {
		// 아직 방문 안했으면
		if (!visited[i]) {
			// 방문
			visited[i] = true;
			seq[idx] = i;
			dfs(idx + 1); // 다음으로
			
			// 되돌리기
			seq[idx] = 0;
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &inning[i][j]);
		}
	}

	// 4번 타자는 1로 고정
	seq[3] = 0;
	visited[0] = true;
	dfs(0);

	printf("%d\n", answer);
	return 0;
}
