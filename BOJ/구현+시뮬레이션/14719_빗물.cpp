// NHN 코딩테스트 문제
// 14719_빗물.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int h, w;
vector<int> height;

int rainy(int idx) {
	int right = 0;
	int left = 0;

	for (int i = idx; i < w; i++) {
		right = max(right, height[i]);
	}

	for (int i = idx; i >= 0; i--) {
		left = max(left, height[i]);
	}

	int h = min(right, left) - height[idx];
	if (h > 0) return h;
	else return 0;
}

int main() {
	scanf("%d %d", &h, &w);

	for (int i = 0; i < w; i++) {
		int rain;
		scanf("%d", &rain);
		height.push_back(rain);
	}

	int answer = 0;
	for (int i = 0; i < w; i++) {
		answer += rainy(i);
	}

	printf("%d\n", answer);
}
