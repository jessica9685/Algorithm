// 9015_정사각형.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> point;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		point.clear(); // 좌표배열 초기화
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			point.push_back({ x, y });
		}

		// x좌표 기준 오름차순 정렬
		sort(point.begin(), point.end());

		int maxSquare = 0;
		// 한 변을 이루는 두 점을 선택 (x좌표가 작은 것부터)
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int dx = point[j].first - point[i].first; // x좌표 차이
				int dy = point[j].second - point[i].second; // y좌표 차이

				// 넓이가 최대값 이하이면 패스
				if (dx * dx + dy * dy <= maxSquare) continue;

				// 정사각형을 이루는 나머지 두 점 
				// i번째 좌표 기준 x좌표가 더 큰 방향으로
				pair<int, int> p1 = { point[i].first + dy, point[i].second - dx};
				pair<int, int> p2 = { point[i].first + (dx + dy), point[i].second - (dx - dy) };

				// 나머지 두 점이 존재한다면 최대값 갱신
				if (binary_search(point.begin(), point.end(), p1) && binary_search(point.begin(), point.end(), p2)) {
					maxSquare = dx * dx + dy * dy;
				}
			}
		}
		printf("%d\n", maxSquare);
	}
	return 0;
}
