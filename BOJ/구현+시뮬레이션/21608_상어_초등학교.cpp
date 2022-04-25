// 21608_상어_초등학교.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct Student {
	int num; // 학생 번호
	int prefer[4]; // 좋아하는 학생
	int y, x; // 자리 위치
};

typedef struct Info {
	int friends; // 인접 친구 수
	int blank; // 인접 빈칸 수
	int y, x; // 현재 행, 열
};

struct comp {
	bool operator()(Info a, Info b) {
		// 인접한 친구가 같으면
		if (a.friends == b.friends) {
			// 빈칸도 같으면
			if (a.blank == b.blank) {
				// 행의 번호도 같으면 열 번호가 작은 순서대로
				if (a.y == b.y) return a.x > b.x;
				// 행의 번호가 작은 순서대로
				else return a.y > b.y;
			}
			// 빈칸이 많은 순서대로 (내림차순)
			else return a.blank < b.blank;
		}
		// 인접한 친구가 많은 순서대로 (내림차순)
		else return a.friends < b.friends;
	}
};

int n;
int board[21][21]; // 교실 자리배치
vector<Student> students;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int score[5] = { 0, 1, 10, 100, 1000 };

int main() {
	scanf("%d", &n);
	students.resize(n * n);
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &students[i].num);
		for (int j = 0; j < 4; j++) {
			scanf("%d", &students[i].prefer[j]);
		}
	}

	// 자리 배치
	for (int s = 0; s < n * n; s++) {
		priority_queue<Info, vector<Info>, comp> pq;

		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= n; x++) {
				// 이미 누가 앉아있으면 패스
				if (board[y][x] != 0) continue;

				Info cur;
				cur.blank = 0, cur.friends = 0;
				cur.y = y, cur.x = x;
				// 인접 칸 탐색
				for (int d = 0; d < 4; d++) {
					int ny = y + dy[d];
					int nx = x + dx[d];

					if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
					// 빈칸 count
					if (board[ny][nx] == 0) cur.blank++;
					// 좋아하는 친구 count
					for (auto f : students[s].prefer) {
						if (board[ny][nx] == f) {
							cur.friends++;
							break;
						}
					}
				}
				pq.push(cur);
			}
		}
		int y = pq.top().y, x = pq.top().x;
		board[y][x] = students[s].num;
		students[s].y = y, students[s].x = x;
	}

	// 점수 계산
	int ans = 0;
	for (int s = 0; s < n * n; s++) {
		int y = students[s].y, x = students[s].x;
		int cnt = 0;
		
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
			for (auto f : students[s].prefer) {
				if (board[ny][nx] == f) {
					cnt++;
					break;
				}
			}
		}

		ans += score[cnt];
	}

	printf("%d\n", ans);
	return 0;
}
