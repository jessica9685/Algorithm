// 1091_카드_섞기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 48

int n;
int p[MAX]; // 최종 목표
int s[MAX]; // 카드 섞는 방법 
int card[MAX]; // 현재 카드 상태

// 카드가 올바르게 섞였는지 확인
bool check() {
	for (int i = 0; i < n; i++) {
		// i번째 카드가 p[i]에게 가지 않으면 false
		if (i % 3 != p[card[i]]) return false;
	}
	return true;
}

void shuffle() {
	int temp[MAX];
	// 카드 섞기
	for (int i = 0; i < n; i++) {
		// i번째 카드를 s[i]번째로 이동
		temp[s[i]] = card[i];
	}
	// 복사
	for (int i = 0; i < n; i++) {
		card[i] = temp[i];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		card[i] = i; // 초기 카드 순서
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; i++) scanf("%d", &s[i]);

	int cnt = 0;
	while (true) {
		if (check()) break; // 올바르게 섞이면 종료
		shuffle(); // 카드 섞기
		cnt++; // 횟수 증가

		// 아무리 섞어도 불가능한 경우
		// 가능한 최대 횟수는 120119번
		if (cnt > 120120) {
			cnt = -1;
			break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
