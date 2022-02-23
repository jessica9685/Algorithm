// 19942_다이어트.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 16
#define INF 987654321

typedef struct food {
	int p; // 단백질
	int f; // 지방
	int s; // 탄수화물
	int v; // 비타민
	int c; // 가격
};

int n;
int mp, mf, ms, mv; // 단백질, 지방, 탄수화물, 비타민
vector<food> foods(MAX);
bool visited[MAX] = { false, };
int cost = INF; // 최소 비용
vector<int> answer; // 최종 선택한 식재료

// 선택된 식재료들의 영양분 합 구하기
void diet(vector<int> eat) {
	food result = { 0, 0, 0, 0, 0 };
	for (auto idx : eat) {
		result.p += foods[idx].p;
		result.f += foods[idx].f;
		result.s += foods[idx].s;
		result.v += foods[idx].v;
		result.c += foods[idx].c;
	}

	// 영양분의 최소합을 만족하고
	if (result.p >= mp && result.f >= mf && result.s >= ms && result.v >= mv) {
		// 최소값이면 정답 배열에 push
		if (cost > result.c) {
			cost = result.c;
			answer.clear();
			answer = eat;
		}
	}
}

// Brute Force
void dfs(int cur, vector<int> eat) {
	// 현재부터 마지막 식재료까지 탐색
	for (int i = cur; i <= n; i++) {
		if (visited[i]) continue; // 이미 방문했으면 패스
		visited[i] = true; // 방문
		eat.push_back(i);
		diet(eat); // 영양분 계산
		dfs(i + 1, eat); // 다음 재료 탐색
		eat.pop_back();
		visited[i] = false; // 방문 취소
	}
	return;
}

int main() {
	scanf("%d", &n);
	scanf("%d %d %d %d", &mp, &mf, &ms, &mv);
	for (int i = 1; i <= n; i++) {
		int p, f, s, v, c;
		scanf("%d %d %d %d %d", &p, &f, &s, &v, &c);
		foods[i] = { p, f, s, v, c };
	}

	// 탐색
	dfs(1, {});

	if (cost != INF) { // 조건을 만족하는 답이 존재하면 출력
		printf("%d\n", cost);
		for (auto ans : answer) {
			printf("%d ", ans);
		}
		printf("\n");
	} 
	// 없으면 -1
	else printf("-1\n");
	return 0;
} 
