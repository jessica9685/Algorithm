// 19238_스타트_택시.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 21

typedef struct customer {
	int num; // 손님 번호 (0부터 시작)
	int cost; // 택시-손님 간 거리
	int y;
	int x; // 손님 위치
};

int n, m, fuel;
int board[MAX][MAX];
int ty, tx; // 택시 출발점
vector<pair<int, int>> start; // 손님 출발점
vector<pair<int, int>> goal; // 손님 목적지
vector<customer> cus;
bool done[401]; // 손님 이동이 끝나면 true
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

// 택시와 가장 가까운 손님을 고르기 위한 비교 함수
bool comp(customer a, customer b) {
	// 거리가 같으면 행 번호가 작은 손님 먼저
	if (a.cost == b.cost) {
		// 행 번호도 같으면 열 번호가 작은 손님 먼저
		if (a.y == b.y) return a.x < b.x;
		else return a.y < b.y;
	}
	else return a.cost < b.cost;
}

// 현재 위치에서 목적지까지의 최단거리
int bfs(int sy, int sx, int ey, int ex) {
	bool visited[MAX][MAX] = { false, };

	visited[sy][sx] = true;
	queue<pair<pair<int, int>, int>> q; // first: 위치, second: 거리
	q.push({ {sy, sx}, 0 });

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		// 목적지에 도착하면 사용한 연료의 양 리턴
		if (y == ey && x == ex) return cost;

		// 다음 정점 탐색
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
			// 아직 방문 안했고, 벽이 아니면 이동
			if (!visited[ny][nx] && board[ny][nx] != 1) {
				visited[ny][nx] = true;
				q.push({ {ny, nx}, cost + 1 });
			}
		}
	}
	// 목적지에 갈 수 없으면 -1 리턴
	return -1;
}

int main() {
	scanf("%d %d %d", &n, &m, &fuel);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	scanf("%d %d", &ty, &tx);
	for (int i = 0; i < m; i++) {
		int sy, sx, ey, ex;
		scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
		start.push_back({ sy, sx });
		goal.push_back({ ey, ex });
	}

	while (true) {
		// 다음 손님 찾기
		cus.clear();
		for (int i = 0; i < m; i++) {
			// 이미 이동 완료한 손님은 패스
			if (done[i]) continue; 
			int cost = bfs(ty, tx, start[i].first, start[i].second);
			// 손님에게 갈 수 없으면 패스
			if (cost == -1) continue;
			cus.push_back({ i, cost, start[i].first, start[i].second });
		}
		// 모든 손님을 다 태웠거나, 벽때문에 다음 손님한테 갈 수 없으면 종료
		if (cus.empty()) break;

		// 우선순위 1번 손님 구하기
		sort(cus.begin(), cus.end(), comp);
		customer next = *cus.begin();

		// 택시->손님 이동 연료
		int texiToCus = next.cost;
		int cusToGoal = bfs(next.y, next.x, goal[next.num].first, goal[next.num].second);

		// 연료가 모자라거나 손님을 목적지로 이동시킬 수 없으면 종료
		if (fuel < texiToCus + cusToGoal || cusToGoal == -1) {
			printf("-1\n");
			return 0;
		}
		// 이동 가능한 경우
		else {
			fuel -= (texiToCus + cusToGoal);
			fuel += (cusToGoal * 2); // 연료 충전
			done[next.num] = true;
			// 택시 위치 수정
			ty = goal[next.num].first;
			tx = goal[next.num].second;
		}
	}

	for (int i = 0; i < m; i++) {
		// 태우지 못한 손님이 있으면 -1
		if (!done[i]) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", fuel);
	return 0;
}
