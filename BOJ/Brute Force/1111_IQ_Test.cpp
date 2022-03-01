// 1111_IQ_Test.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int n;
int seq[MAX];

// 규칙 성립 여부 판단
bool check(int r, int d) {
	for (int i = 0; i < n - 1; i++) {
		// 규칙이 성립되지 않으면 false
		if (seq[i + 1] != seq[i] * r + d) return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	
	// 수열 크기가 3 이상이면
	if (n >= 3) {
		// 공비(r), 공차(d) 구하기 (r, d는 모두 정수)
		int a = seq[0], b = seq[1], c = seq[2];
		int r, d;
		if (b - a == 0) r = 1;
		else r = (c - b) / (b - a);
		d = b - (a * r);

		// r, d가 규칙을 만족하면 다음 수 출력
		if (check(r, d)) {
			int next = seq[n - 1] * r + d;
			printf("%d\n", next);
		}
		// 만족 X -> "B" 출력
		else printf("B\n");
	}
	// 수열 크기가 2 이하이면
	else {
		// 수열 크기가 2이면서
		if (n == 2) {
			// 두 수가 모두 같으면 규칙 1개 존재
			if (seq[0] == seq[1]) printf("%d\n", seq[0]);
			else printf("A\n");
		}
		// 그 외의 경우 규칙이 여러 개일 수 있음 -> "A" 출력
		else printf("A\n");
	}
	return 0;
}
