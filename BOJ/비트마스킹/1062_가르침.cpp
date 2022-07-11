// 1062_가르침.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, K;
int words[50]; // 단어
int answer; // 읽을 수 있는 단어 수
int visited; // 배운 문자

// k: 남은 문자 수, visited: 배운 문자들 표시
void dfs(int k, int idx) {
	if (k == 0) {
		int cnt = 0; // 읽을 수 있는 문자 수
		for (int i = 0; i < n; i++) {
			if ((words[i] & visited) == words[i]) cnt++;
		}
		// 최대값 갱신
		if (answer < cnt) answer = cnt;
		return;
	}

	// 다음으로 배울 문자 탐색
	for (int i = idx; i < 26; i++) {
		// 방문 안한 경우
		// !! 주의 !! '==' 연산순위가 '&'보다 높다
		if ((visited & (1 << i)) == 0) {
			visited |= (1 << i); // 방문
			dfs(k - 1, i);
			visited &= ~(1 << i); // 방문 취소
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> K;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		
		// 문자열을 비트로 표현
		int num = 0;
		for (int j = 0; j < str.length(); j++) {
			num |= (1 << (str[j] - 'a'));
		}
		words[i] = num;
	}

	// a, n, t, i, c 5개는 무조건 읽을 수 있어야 함
	if (K < 5) answer = 0;
	else if (K == 26) answer = n;
	else {
		visited |= (1 << ('a' - 'a'));
		visited |= (1 << ('n' - 'a'));
		visited |= (1 << ('t' - 'a'));
		visited |= (1 << ('i' - 'a'));
		visited |= (1 << ('c' - 'a'));

		dfs(K - 5, 0);
	}
	printf("%d\n", answer);
	return 0;
}
