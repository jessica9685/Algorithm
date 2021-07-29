// 11049_행렬_곱셈_순서.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct Matrix {
	int r, c;
};

int N;
vector<Matrix> matrix;
int dp[500][500]; // 행렬 i부터 j까지의 최소 곱셈 횟수

int divideConquer(int start, int end) {
	// 자기 자신이면 0
	if (start == end) return 0;

	// 이미 갱신됐으면 리턴
	if (dp[start][end] != INT_MAX) return dp[start][end];

	// 분할정복
	for (int i = start; i < end; i++) {
		int left = divideConquer(start, i);
		int right = divideConquer(i + 1, end);

		dp[start][end] = min(dp[start][end],
			left + right + matrix[start].r * matrix[i].c * matrix[end].c);
	}

	return dp[start][end];
}

int main() {
	scanf("%d", &N);

	matrix.resize(N, { 0, 0 });
	for (int i = 0; i < N; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		matrix[i] = { r, c };
		// dp 초기화
		for (int j = 0; j < N; j++) dp[i][j] = INT_MAX;
	}

	int result = divideConquer(0, N - 1);
	printf("%d\n", result);
}
