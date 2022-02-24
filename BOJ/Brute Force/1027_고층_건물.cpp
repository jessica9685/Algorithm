// 1027_고층_건물.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int n;
vector<int> height(MAX); // 각 건물의 높이
int visible[MAX] = { 0, }; // 각 건물에서 보이는 건물 수

// b1 건물에서 b2 건물이 보이면 true
bool isVisible(int b1, int b2) {
	// y = ax + b
	double a = (double)(height[b2] - height[b1]) / (double)(b2 - b1);
	double b = (double)height[b1] - a * b1;

	// 두 건물 사이에 있는 건물이 y = ax + b와 겹치면 false
	for (int i = b1 + 1; i < b2; i++) {
		if (height[i] >= a * i + b) return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &height[i]);
	}

	// 왼쪽부터 오른쪽으로 탐색
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// i 건물에서 j 건물이 보이면 
			if (isVisible(i, j)) {
				visible[i]++;
				visible[j]++;
			}
		}
	}

	// 최댓값 구하기
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (answer < visible[i]) answer = visible[i];
	}
	printf("%d\n", answer);
	return 0;
}
