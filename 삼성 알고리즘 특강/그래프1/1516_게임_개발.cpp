// 1516_게임_개발.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 500 + 1

int n;

typedef struct build {
	int time = 0; // 해당 건물을 짓는데 걸리는 시간
	int inDegree = 0; // 선행으로 지어야 할 건물 수
	int minTotal = 0; // 선행건물 포함 최소 건설 시간
	vector<int> outBuild; // 이후 지어져야할 건물 리스트
};

int main() {
	scanf("%d", &n);
	
	// building 벡터 초기화
	vector<build> building(n + 1);

	for (int i = 1; i <= n; i++) {
		int time; // 건물 건설 시간
		scanf("%d", &time);
		building[i].time = time;

		// -1이 나올 때까지 입력받음
		while (true) {
			int num;
			scanf("%d", &num);
			if (num == -1) break;
			// i == 현재 건물, num == 선행 건물
			building[num].outBuild.push_back(i); // 선행 건물들의 이후 건설 리스트에 현재 건물 추가 
			building[i].inDegree++; // 선행 건물 개수 증가
		}
	}

	// 선행건물이 없는 경우 (inDegree == 0) 큐에 넣기
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (building[i].inDegree == 0) q.push(i);
	}

	// 위상정렬
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		// 최소 건물 건설 시간 = 이전까지의 건물 건설 시간 + 현재 건물 건설 시간
		building[cur].minTotal += building[cur].time;

		// 선행 건물의 건설이 끝났으므로 이후 건물들에 대해 변수 갱신
		for (auto next : building[cur].outBuild) {
			building[next].inDegree--; // 선행건물 수 감소
			// 다음 건물의 최소 건설 시간 == (선행 건물의 최소 건설 시간)과 (다음 건물의 최소건설 시간)의 최댓값
			// why? 건물의 동시 건설이 가능하기 때문에 
			building[next].minTotal = max(building[cur].minTotal, building[next].minTotal);

			if (building[next].inDegree == 0) {
				q.push(next);
			}
		}
	}

	// 각 건물의 최소 건설 시간 출력
	for (int i = 1; i <= n; i++) {
		printf("%d\n", building[i].minTotal);
	}
	return 0;
}
