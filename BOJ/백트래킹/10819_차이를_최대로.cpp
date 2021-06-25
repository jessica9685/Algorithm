// 10819_차이를_최대로.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[8];
int new_arr[8]; // 새로 만든 순열
bool visited[8]; 
int answer;

// 순열 계산
void calc() {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += abs(new_arr[i] - new_arr[i + 1]);
	}
	answer = max(sum, answer);
}

void dfs(int idx) {
	if (idx == n) {
		calc();
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		new_arr[idx] = arr[i];
		dfs(idx + 1);
		visited[i] = false;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dfs(0);

	printf("%d\n", answer);
	return 0;
}
