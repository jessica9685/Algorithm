// 9019_DSLR.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

int a, b;
bool visited[MAX];

void bfs() {
	queue<pair<int, string>> q; // first: 숫자, second: 명령
	q.push({ a, "" });
	visited[a] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		string op = q.front().second;
		q.pop();

		// 목표에 도달하면 종료
		if (cur == b) {
			cout << op << "\n";
			return;
		}

		int D, S, L, R;
		// D 연산
		D = (cur * 2) % 10000;
		if (!visited[D]) {
			visited[D] = true;
			q.push({ D, op + "D" });
		}

		// S 연산
		S = cur - 1 < 0 ? 9999 : cur - 1;
		if (!visited[S]) {
			visited[S] = true;
			q.push({ S, op + "S" });
		}

		// L 연산
		L = (cur % 1000) * 10 + (cur / 1000);
		if (!visited[L]) {
			visited[L] = true;
			q.push({ L, op + "L" });
		}

		// R 연산
		R = (cur / 10) + (cur % 10) * 1000;
		if (!visited[R]) {
			visited[R] = true;
			q.push({ R, op + "R" });
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		memset(visited, false, sizeof(visited));
		bfs();
	}
	return 0;
}
