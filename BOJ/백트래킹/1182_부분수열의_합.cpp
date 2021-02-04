// 1182_부분수열의_합.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX 20

int n, s;
int answer = 0;
vector<int> arr;

void dfs(int idx, int sum) {
	sum += arr[idx];
	
	if (idx >= n) return;
	if (sum == s) answer++;

	// 현재 숫자를 더했을 경우
	dfs(idx + 1, sum);

	// 현재 숫자를 더하지 않았을 경우
	dfs(idx + 1, sum - arr[idx]);
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	dfs(0, 0);
	printf("%d\n", answer);
}

