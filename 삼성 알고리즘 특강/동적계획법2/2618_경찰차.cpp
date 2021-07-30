// 2618_경찰차.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct point {
	int y;
	int x;
};

int n, w;
vector<vector<int>> road;
vector<point> cases;
int dp[1001][1001]; // dp[i][j] : 1번 경찰차가 i번 사건 처리 + 2번 경찰차가 j번 사건 처리
vector<int> solvedCases;

int dist(point a, point b) {
	return abs(b.y - a.y) + abs(b.x - a.x);
}

// 최소 거리 구하기
int getTotalDist(int police1, int police2) {
	// 마지막 사건 처리하면 탈출
	if (police1 == w || police2 == w) {
		return 0;
	}
	// 이미 계산한 dp면 넘어감
	if (dp[police1][police2] != -1) {
		return dp[police1][police2];
	}
	
	// 다음 사건 계산
	int next = max(police1, police2) + 1;

	// 경찰1이 해결할 경우 거리
	int dist1;
	if (police1 == 0) dist1 = dist({ 1, 1 }, cases[next]);
	else dist1 = dist(cases[police1], cases[next]);
	dist1 += getTotalDist(next, police2);

	// 경찰2가 해결할 경우 총 거리
	int dist2;
	if (police2 == 0) dist2 = dist({ n, n }, cases[next]);
	else dist2 = dist(cases[police2], cases[next]);
	dist2 += getTotalDist(police1, next);

	// 최솟값 구하기
	return dp[police1][police2] = min(dist1, dist2);
}

// 각 사건을 해결한 경찰차 구하기
void whoSolved(int police1, int police2) {
	if (police1 == w || police2 == w) return;

	int next = max(police1, police2) + 1;

	// 경찰1이 해결할 경우 거리
	int dist1;
	if (police1 == 0) dist1 = dist({ 1, 1 }, cases[next]);
	else dist1 = dist(cases[police1], cases[next]);
	dist1 += dp[next][police2];

	// 경찰2가 해결할 경우 총 거리
	int dist2;
	if (police2 == 0) dist2 = dist({ n, n }, cases[next]);
	else dist2 = dist(cases[police2], cases[next]);
	dist2 += dp[police1][next];

	// 경찰1이 가는 거리가 더 짧으면
	if (dist1 < dist2) {
		solvedCases.push_back(1);
		whoSolved(next, police2);
	}
	else {
		solvedCases.push_back(2);
		whoSolved(police1, next);
	}
}

int main() {
	scanf("%d", &n);
	road.resize(n + 1, vector<int>(n + 1, 0));
	
	scanf("%d", &w);
	cases.resize(w + 1, { 0, 0 });
	for (int i = 1; i <= w; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		cases[i] = { y, x };
	}

	memset(dp, -1, sizeof(dp));
	int minDist = getTotalDist(0, 0);
	printf("%d\n", minDist);
	whoSolved(0, 0);
	for (auto p : solvedCases) {
		printf("%d\n", p);
	}

	return 0;
}
