// 15686_치킨_배달.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int N, M;
int city[51][51];
bool visited[13] = { false, };
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int result; // 치킨거리

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

// idx: 치킨집 인덱스, cnt: 남겨진 치킨집 수
void dfs(int idx, int cnt) {
	if (cnt == M) {
		int chickenDist = 0;
		for (auto h : house) { // 각 집의 최소 치킨 거리 구하기
			int tmp = INF;
			for (int c = 0; c < chicken.size(); c++) {
				if (visited[c]) { // 선택된 치킨집이면
					tmp = min(tmp, dist(h, chicken[c]));
				}
			}
			chickenDist += tmp;
		}

		if (result > chickenDist) result = chickenDist;
		return;
	}

	// idx 범위 벗어나면 종료
	if (idx == chicken.size()) return;

	// 치킨집 생존 (남길 치킨집 선택)
	visited[idx] = true;
	dfs(idx + 1, cnt + 1);

	// 치킨집 폐업
	visited[idx] = false;
	dfs(idx + 1, cnt);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &city[i][j]);

			// 집, 치킨집 좌표 저장
			if (city[i][j] == 2) chicken.push_back({ i, j });
			else if (city[i][j] == 1) house.push_back({ i, j });
		}
	}

	result = INF;
	dfs(0, 0);

	printf("%d\n", result);
	return 0;
}
