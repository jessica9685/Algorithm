// 1107_리모컨.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

/* 최대한 숫자를 먼저 다 누른 후 +, -를 조작해야 함 */

bool broken[10] = { false, }; // 고장난 버튼이면 true

int check(int n) { // n으로 이동하기 위해 눌러야하는 숫자 버튼 횟수
	if (n == 0) {
		if (broken[n]) return 0; // 0 고장
		else return 1; // 0을 1번 눌러서 접근 가능
	}
	
	int len = 0;
	while (n > 0) {
		if (broken[n % 10]) return 0;
		n /= 10;
		len++;
	}

	return len;
}

int main() {
	int n; // channel
	int m; // broken button
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int b;
		scanf("%d", &b);
		broken[b] = true;
	}

	// 처음 시작 위치 == 100
	int answer = abs(n - 100); // 버튼 눌러야 하는 횟수
	
	// n은 500,000 이하지만 실제로는 1,000,000(n*2)까지 가능
	for (int i = 0; i < 1000000; i++) {
		int len = check(i);
		if (len > 0) {
			answer = min(answer, abs(n - i) + len);
		}
	}

	printf("%d\n", answer);
}
