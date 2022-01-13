// 19238_스타트_택시.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 21

typedef struct customer {
	int num; // 손님 번호
	int cost; // 택시-손님 간 거리
	int r; // 손님 위치(행)
	int c; // 손님 위치(열)
};

int n, m, fuel;
int maps[MAX][MAX];
int ty, tx; // 택시 출발점
vector<pair<int, int>> start; // 손님 출발점
vector<pair<int, int>> goal; // 손님 도착점
vector<customer> cus; // 택시-손님 간 거리
bool visited[MAX][MAX] = { false, };
bool check[401] = { false, }; // 손님 이동시키면 true
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool comp(customer a, customer b) {
	if (a.cost == b.cost) { // a, b 손님까지의 거리가 같으면
		if (a.r == b.r) return a.c < b.c; // 행 번호도 같으면 열 번호 더 작은 순서대로
		return a.r < b.r; // 행 번호가 더 작은 순서대로
	}
	return a.cost < b.cost; // 거리가 더 짧은 손님에게 ㄱ
}

// 현재 위치에서 목적지까지의 최단거리
int shortest_path(int sy, int sx, int ey, int ex) {
	memset(visited, false, sizeof(visited));

	visited[sy][sx] = true;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {sy, sx}, 0 });

	while (!q.empty()) {
		int cur_y = q.front().first.first;
		int cur_x = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		// 목적지에 도착하면 사용된 연료의 양 리턴
		if (cur_y == ey && cur_x == ex) return cost;

		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny <= 0 || nx <= 0 || ny > n || nx > n) continue;
			if (!visited[ny][nx] && maps[ny][nx] == 0) {
				visited[ny][nx] = true;
				q.push({ {ny, nx}, cost + 1 });
			}
		}
	}

	// 목적지에 도착하지 못하면 -1
	return -1;
}

int main() {
	scanf("%d %d %d", &n, &m, &fuel);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) scanf("%d", &maps[i][j]);
	}
	scanf("%d %d", &ty, &tx);
	for (int i = 0; i < m; i++) {
		int sy, sx, ey, ex; // 손님 출발/도착점
		scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
		start.push_back({ sy, sx });
		goal.push_back({ ey, ex });
	}

	while (true) {
		// 다음 손님 선택
		cus.clear();
		for (int i = 0; i < m; i++) {
			if (check[i]) continue;
			int path = shortest_path(ty, tx, start[i].first, start[i].second);
			if (path == -1) continue; // 갈 수 없으면 continue
			cus.push_back({ i, path, start[i].first, start[i].second });
		}
		// 모든 승객을 다 데려다준 경우 + 벽에 막혀 다음 손님에게 갈 수 없을 경우에도 종료
		if (cus.empty()) break; 
		sort(cus.begin(), cus.end(), comp);
		customer next = *cus.begin();

		// 다음 손님을 이동시키는데 드는 연료
		int texiToCus = next.cost;
		int cusToGoal = shortest_path(next.r, next.c, goal[next.num].first, goal[next.num].second);

		// 연료가 모자라거나 손님을 목적지로 데려댜줄 수 없으면 종료
		if (fuel < texiToCus + cusToGoal || cusToGoal == -1) {
			printf("-1\n");
			return 0;
		}
		else { // 이동 가능하면
			fuel -= (texiToCus + cusToGoal);
			fuel += (cusToGoal * 2); // 연료 충전
			check[next.num] = true; // 손님 방문 표시
			// 택시 위치 변경
			ty = goal[next.num].first;
			tx = goal[next.num].second;
		}
	}

	for (int i = 0; i < m; i++) {
		if (!check[i]) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", fuel);
	return 0;
}
