// 17406_배열_돌리기4.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51
#define INF 10000

typedef struct op {
	int r, c; // r행 c열
	int s; 
} op;

int arr[MAX][MAX];
int origin[MAX][MAX];
int k; // 연산 횟수
int n, m;
op oper[6];
op new_oper[6];
// 연산 순서를 정하기 위한 방문 배열
bool visited[6] = { false, }; 
int answer;

// 회전 연산
void rotate(int r, int c, int S) {
	int copied[MAX][MAX];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			copied[i][j] = arr[i][j];
		}
	}

	for (int s = 1; s <= S; s++) {
		// (r-s)행, (r+s)행 이동
		for (int j = c - s; j < c + s; j++) {
			arr[r - s][j + 1] = copied[r - s][j];
			arr[r + s][j] = copied[r + s][j + 1];
		}

		// (c-s)열, (c+s)열 이동
		for (int i = r - s; i < r + s; i++) {
			arr[i + 1][c + s] = copied[i][c + s];
			arr[i][c - s] = copied[i + 1][c - s];
		}
	}
}

// 배열 A의 최솟값
int calc() {
	int result = INF;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += arr[i][j];
		}
		if (result > sum) result = sum;
	}

	return result;
}

// 연산 순서를 정하기 위한 dfs
void dfs(int idx) {
	if (idx == k) {
		// 연산 순서대로 연산
		for (int i = 0; i < k; i++) {
			op cur = new_oper[i];
			rotate(cur.r, cur.c, cur.s);
		}
		// 최솟값 구하기
		int res = calc();
		if (answer > res) answer = res;

		// 원래 배열로 되돌리기
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				arr[i][j] = origin[i][j];
			}
		}
		return;
	}

	for (int i = 0; i < k; i++) {
		if (visited[i]) continue;
		// 방문 안했으면
		visited[i] = true; // 방문
		new_oper[idx] = oper[i]; // 추가
		dfs(idx + 1); // 다음으로
		// 되돌리기
		visited[i] = false;
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			origin[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c, s;
		scanf("%d %d %d", &r, &c, &s);
		oper[i] = { r, c, s };
	}
	
	answer = INF;
	dfs(0);
	printf("%d\n", answer);
	return 0;
}
