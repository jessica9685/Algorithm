// 11266_단절점.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int v, e, order, ans; // ans: 단절점 개수, order: 방문 순서
vector<int> graph[MAX];
vector<int> visited; // 각 정점의 방문순서(order) 저장
vector<bool> isCut; // i가 단절점이면 isCut[i] = true

// cur : 현재 정점(A)
int dfs(int cur, bool isRoot) {
	// 현재 정점의 방문순서 표시
	visited[cur] = order;
	order++;

	int ret = visited[cur]; // 자식의 최소 방문순서
	int child = 0; // 자식의 개수는 root일 경우에만 의미가 있음

	// 자식들 방문
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];

		// 자식을 최초로 방문했을 경우 -> low 찾기
		if (visited[next] == 0) {
			child++;
			// 방문 안한 자식들 중 최소 order
			int low = dfs(next, false);

			// root가 아니고, order[cur] <= low이면 단절점
			if (!isRoot && visited[cur] <= low) {
				isCut[cur] = true;
			}
			ret = min(ret, low);
		}
		// 자식을 이미 방문했을 경우
		// 알고보니 조상님...
		else {
			// 최소 order를 반환
			ret = min(ret, visited[next]);
		}
	}

	// 루트정점이고, 자식 개수가 2개 이상이면 단절점
	if (isRoot && child >= 2) {
		isCut[cur] = true;
	}

	return ret;
}

int main() {
	scanf("%d %d", &v, &e);

	visited.resize(v + 1, 0);
	isCut.resize(v + 1, false);

	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// dfs로 방문하면서 단절점 찾기
	order = 1; 
	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			dfs(i, true);
		}
	}

	// 단절점과 개수 출력
	ans = 0;
	vector<int> cutPoint;
	for (int i = 1; i <= v; i++) {
		if (isCut[i]) {
			ans++;
			cutPoint.push_back(i);
		}
	}

	sort(cutPoint.begin(), cutPoint.end());
	printf("%d\n", ans);
	for (auto p : cutPoint) {
		printf("%d ", p);
	}
	printf("\n");
	return 0;
}
