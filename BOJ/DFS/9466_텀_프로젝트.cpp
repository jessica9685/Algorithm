// 9466_텀_프로젝트.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

int T, n, members;
int selected[MAX];
bool visited[MAX] = { false, };
bool done[MAX] = { false, }; // 더 이상 방문 안해도 되면 true

// 사이클 찾기
void dfs(int cur) {
	// 현재 정점 방문
	visited[cur] = true;

	// 다음 정점 탐색
	int next = selected[cur];
	if (!visited[next]) dfs(next); // 방문 안한 경우
	// 이미 방문했지만 방문이 아직 끝나지 않은 경우 -> 사이클
	else if (!done[next]) {
		// next부터 현재 정점까지의 팀원 수 세기
		for (int i = next; i != cur; i = selected[i]) members++;
		members++; // cur 자신
	}

	// 방문 끝내기
	done[cur] = true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &selected[i]);
		}

		// 초기화
		members = 0;
		for (int i = 1; i <= n; i++) {
			done[i] = false;
			visited[i] = false;
		}

		// 사이클 찾기
		for (int i = 1; i <= n; i++) {
			// visited를 일일이 초기화하면 시간초과
			// 방문하지 않은 학생에 대해서만 탐색
			if (!visited[i]) dfs(i);
		}

		// 팀이 없는 학생 찾기
		int ans = n - members;
		printf("%d\n", ans);
	}
	return 0;
}
