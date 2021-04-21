// 20055_컨베이어_벨트_위의_로봇.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 202

int n, k;
int belt[MAX];
bool visited[MAX] = { false, };

int main() {
	scanf("%d %d", &n, &k);
	int cnt = 0; // 내구도가 0인 칸의 수
	for (int i = 1; i <= 2 * n; i++) {
		scanf("%d", &belt[i]);
		if (belt[i] == 0) cnt++;
	}

	int steps = 0; // 수행한 단계 수
	int start = 1; // 올라가는 위치
	int end = n; // 내려가는 위치

	queue<int> q; // 로봇의 위치를 저장한 큐

	while (cnt < k) {
		steps++; // 1단계부터 시작

		/* step 1: 벨트 1칸 회전 */
		start--;
		end--;
		if (start < 1) start = 2 * n;
		if (end < 1) end = 2 * n;

		/* step 2: 로봇 1칸 이동 */
		int s = q.size(); // 중간중간 큐 사이즈가 계속 바뀌기 때문에 변수에 따로 저장하기!!!
		for (int i = 0; i < s; i++) {
			int cur = q.front();
			visited[cur] = false;
			q.pop();

			// 로봇이 내려가는 위치에 있었으면 지워버림
			if (cur == end) continue;

			int next = cur + 1;
			if (next > 2 * n) next = 1;
			// 내구도가 1 이상이고 해당 칸에 로봇이 없으면 이동
			if (belt[next] >= 1 && !visited[next]) {
				belt[next]--; // 내구도 감소
				if (belt[next] == 0) cnt++;
				if (next == end) continue; // 이동한 부분이 내려가는 위치면 지움
				visited[next] = true;
				q.push(next);
			}
			else { // 이동 못할 경우
				visited[cur] = true;
				q.push(cur);
			}
		}

		/* step 3: 올라가는 위치에 로봇 올리기 */
		// 올라가는 위치에 로봇 없고, 내구도 1 이상이면
		if (!visited[start] && belt[start] >= 1) {
			visited[start] = true; // 로봇 올리고
			belt[start]--; // 내구도 감소
			if (belt[start] == 0) cnt++;
			q.push(start); // 큐에 삽입
		}
	}

	printf("%d\n", steps);
	return 0;
}
