// 17140_이차원_배열과_연산.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int r, c, k;
int arr[MAX][MAX];
int numCnt[MAX]; // 각 숫자 개수

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int ans = 0;
	int time = 0;
	int row = 3;
	int col = 3;
	while (true) {
		if (arr[r][c] == k) { // 조건 만족 시 종료
			ans = time; 
			break;
		}
		if (time > 100) { // 시간초과시 종료
			ans = -1;
			break;
		}
		int s = 0; // 최대 열/행 크기
		// r 연산
		if (row >= col) {
			for (int i = 1; i <= row; i++) {
				vector<pair<int, int>> vec; // first: 개수, second: 수
				memset(numCnt, 0, sizeof(numCnt));
				// 각 행에 있는 숫자의 개수 세기
				for (int j = 1; j <= col; j++) numCnt[arr[i][j]]++;
				for (int j = 1; j < MAX; j++) {
					if (numCnt[j] == 0) continue;
					vec.push_back({ numCnt[j], j });
				}
				// 횟수 오름차순 정렬 (같으면 수 오름차순)
				sort(vec.begin(), vec.end());

				for (int j = 1; j <= col; j++) arr[i][j] = 0;
				int idx = 1;
				for (int j = 0; j < vec.size(); j++) {
					arr[i][idx++] = vec[j].second;
					arr[i][idx++] = vec[j].first;
				}
				s = max(--idx, s);
			}
			col = s;
		}
		// c 연산
		else {
			for (int i = 1; i <= col; i++) {
				vector<pair<int, int>> vec; // first: 개수, second: 수
				memset(numCnt, 0, sizeof(numCnt));
				// 각 행에 있는 숫자의 개수 세기
				for (int j = 1; j <= row; j++) numCnt[arr[j][i]]++;
				for (int j = 1; j < MAX; j++) {
					if (numCnt[j] == 0) continue;
					vec.push_back({ numCnt[j], j });
				}
				// 횟수 오름차순 정렬 (같으면 수 오름차순)
				sort(vec.begin(), vec.end());

				for (int j = 1; j <= row; j++) arr[j][i] = 0;
				int idx = 1;
				for (int j = 0; j < vec.size(); j++) {
					arr[idx++][i] = vec[j].second;
					arr[idx++][i] = vec[j].first;
				}
				s = max(--idx, s);
			}
			row = s;
		}
		time++;
	}

	printf("%d\n", ans);
}
