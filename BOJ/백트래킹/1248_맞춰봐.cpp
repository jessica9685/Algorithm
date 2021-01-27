// 1248_맞춰봐.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n; // 수열의 크기
char state[10][10]; // S[i][j]
int seq[10]; // 수열

/* 수열의 원소가 부호와 부합하면 true */
bool check(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--) {
		sum += seq[i]; // state[i][idx]
		if (state[i][idx] == '+' && sum <= 0) return false;
		if (state[i][idx] == '-' && sum >= 0) return false;
		if (state[i][idx] == '0' && sum != 0) return false;
	}
	return true;
}

void dfs(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", seq[i]);
		}
		printf("\n");
		exit(0); // 그냥 리턴하면 여러 경우의 수가 나와버림..(출력초과)
	}

	for (int i = -10; i <= 10; i++) {
		seq[cnt] = i;
		if (check(cnt)) dfs(cnt + 1);
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			scanf(" %c", &state[i][j]);
		}
	}

	dfs(0);
}
