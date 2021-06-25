// 6603_로또.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int k;
int s[13];
int lotto[6];

void dfs(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", lotto[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i < k; i++) {
		lotto[cnt] = s[i];
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	while (true) {
		scanf("%d", &k);

		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			scanf("%d", &s[i]);
		}
		dfs(0, 0);
		printf("\n");
	}
	exit(0);
}
