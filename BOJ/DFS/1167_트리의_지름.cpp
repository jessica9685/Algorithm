// 1167_트리의_지름.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
#define MAX 100001
#define INF 987654321

typedef struct Node {
	int next; // 연결된 정점
	int d; // 거리
};

int v; // 정점의 개수
vector<Node> graph[MAX]; // 트리
bool visited[MAX];
int maxDist = 0;
int maxNode;

void dfs(int node, int len) {
	// 이미 방문한 정점이면 패스
	if (visited[node]) return;

	// max값 갱신
	if (maxDist < len) {
		maxDist = len;
		maxNode = node;
	}

	visited[node] = true; // 방문 표시

	for (auto node : graph[node]) {
		if (visited[node.next]) continue;
		dfs(node.next, len + node.d);
	}
}

int main() {
	scanf("%d", &v);
	for (int i = 0; i < v; i++) {
		int start;
		scanf("%d", &start);

		while (true) {
			int next, dist;
			scanf("%d", &next);

			if (next == -1) break;
			else scanf("%d", &dist);

			graph[start].push_back({ next, dist });
		}
	}

	// 모든 정점에 대해 탐색하면 시간초과 발생
	// 임의의 정점 1에서 가장 거리가 먼 정점 찾기
	dfs(1, 0);
	// visited 초기화
	memset(visited, false, sizeof(visited));
	// 정점 1과 가장 먼 거리에 있는 정점에서 다시 dfs 수행
	dfs(maxNode, 0);

	printf("%d\n", maxDist);
	return 0;
}
