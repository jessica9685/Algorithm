// 2564_경비원.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int store[101];

int main() {
	scanf("%d %d", &n, &m); // 가로, 세로
	scanf("%d", &k); // 상점 수
	for (int i = 0; i <= k; i++) { // store[k]는 동근이의 위치
		int dir, dist;
		scanf("%d %d", &dir, &dist);
		switch (dir) {
			case 1: // 북(x축) 
				store[i] = dist;
				break;
			case 2: // 남 
				store[i] = 2 * n + m - dist;
				break;
			case 3: // 서
				store[i] = 2 * (n + m) - dist;
				break;
			case 4: // 동
				store[i] = n + dist;
				break;
		}
	}

	int sum = 0;
	for (int i = 0; i < k; i++) {
		int path = abs(store[i] - store[k]);
		sum += min(path, 2 * (n + m) - path);
	}
	printf("%d\n", sum);
	return 0;
}
