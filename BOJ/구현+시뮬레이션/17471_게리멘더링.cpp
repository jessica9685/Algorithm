// 17471_게리멘더링.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 11
#define INF 987654321

int n;
vector<int> graph[MAX];
int people[MAX];
bool visitedA[MAX] = { false, };
vector<vector<int>> areaA, areaB;
vector<int> tempA, tempB;
int answer = INF;

// 선거구가 적절한지(서로 연결되어 있는지) 확인
bool isConnected(vector<int> area) {
	// 초기화
	bool visited[MAX] = { false, };
	int start = area[0];
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int cnt = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (visited[next] || find(area.begin(), area.end(), next) == area.end()) continue;
			visited[next] = true;
			cnt++;
			q.push(next);
		}
	}

	if (cnt == area.size()) return true;
	else return false;
}

// 인구 차 구하기
int sub(vector<int> a, vector<int> b) {
	// A의 인구 수
	int sumA = 0;
	for (int i = 0; i < a.size(); i++) {
		sumA += people[a[i]];
	}
	// B의 인구 수 
	int sumB = 0;
	for (int i = 0; i < b.size(); i++) {
		sumB += people[b[i]];
	}

	// A와 B의 인구 차
	int result = abs(sumA - sumB);
	if (answer > result) {
		answer = result;
	}

	return result;
}

// 선거구 나누는 경우의 수 구하기 (조합)
void dfs(int cnt, int goal) {
	if (cnt == goal) {
		tempB.clear();
		for (int i = 1; i <= n; i++) {
			if (!visitedA[i]) tempB.push_back(i);
		}
		areaA.push_back(tempA);
		areaB.push_back(tempB);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visitedA[i]) continue;
		visitedA[i] = true;
		tempA.push_back(i);
		dfs(cnt + 1, goal);
		
		// 되돌리기
		visitedA[i] = false;
		tempA.pop_back();
	}
}

int main() {
	scanf("%d", &n);
	// 인구 수
	for (int i = 1; i <= n; i++) {
		scanf("%d", &people[i]);
	}

	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int next;
			scanf("%d", &next);
			graph[i].push_back(next);
		}
	}

	for (int i = 1; i <= n / 2; i++) {
		// 초기화
		tempA.clear();
		for (int j = 1; j <= n; j++) visitedA[j] = false;

		// 조합 구하기
		dfs(0, i);
	}

	for (int i = 0; i < areaA.size(); i++) {
		if (isConnected(areaA[i]) && isConnected(areaB[i])) {
			int sum = sub(areaA[i], areaB[i]);
			if(answer > sum) answer = sum;
		}
	}

	if (answer != INF) printf("%d\n", answer);
	else printf("-1\n");
	return 0;
}
