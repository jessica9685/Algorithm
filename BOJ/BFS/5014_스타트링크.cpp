// 5014_스타트링크.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int f, s, g, u, d;
int visited[MAX];

int bfs(int start) {
	visited[start] = 1;
	queue<pair<int, int>> q;
	q.push({ start, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cur_cnt = q.front().second;
		q.pop();

		if (cur == g) return cur_cnt;
		if (cur + u <= f && !visited[cur + u]) {
			q.push({ cur + u, cur_cnt + 1 });
			visited[cur + u] = 1;
		}
		if (cur - d > 0 && !visited[cur - d]) {
			q.push({ cur - d, cur_cnt + 1 });
			visited[cur - d] = 1;
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> f >> s >> g >> u >> d;
	int ans = bfs(s);

	if (ans == -1) cout << "use the stairs" << endl;
	else cout << ans << endl;
}
