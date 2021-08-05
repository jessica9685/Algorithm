// 1039_교환.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, K;
string n;
bool visited[1000001][11] = { false, };

int main() {
	scanf("%d %d", &N, &K);
	n = to_string(N);

	// 연산을 K번 할 수 없는 경우
	if (n.size() == 1) printf("-1\n");
	else {
		// first: 현재 상태 string, second: 연산 횟수
		queue<pair<string, int>> q; 
		int ans = 0;
		q.push({ n, 0 });

		while (!q.empty()) {
			string cur = q.front().first;
			int cnt = q.front().second;
			q.pop();

			// K번 연산이 끝나면 answer을 최대값으로 갱신
			if (cnt == K) {
				ans = max(ans, stoi(cur));
				continue;
			}

			// 연산
			for (int i = 0; i < cur.size() - 1; i++) {
				for (int j = i + 1; j < cur.size(); j++) {
					swap(cur[i], cur[j]); // swap
					// 맨 앞이 0이거나 이미 방문했으면
					if (cur[0] == '0' || visited[stoi(cur)][cnt + 1]) {
						swap(cur[i], cur[j]); // 원래대로 돌리고
						continue;
					}
					// 방문 가능하면
					else { 
						q.push({ cur, cnt + 1 }); // 큐에 넣고
						visited[stoi(cur)][cnt + 1] = true; // 방문표시
						swap(cur[i], cur[j]); // 이전 상태로 돌리기
					}
				}
			}
		}

		if (ans == 0) printf("-1\n");
		else printf("%d\n", ans);
	}

	return 0;
}
