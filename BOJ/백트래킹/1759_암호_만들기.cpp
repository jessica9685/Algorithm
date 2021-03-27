// 1759_암호_만들기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 16

int L, C;
char secret[MAX];

// con: 자음개수, vow: 모음 개수
// pos: secret의 인덱스
void combination(int pos, string pw, int con, int vow) {
	if (pw.size() == L) {
		// 자음이 2개 미만이거나 모음이 없을 경우
		if (con < 2 || vow < 1) return;
		else cout << pw << endl;
	}

	for (int i = pos; i < C; i++) {
		// 모음인 경우
		if (secret[i] == 'a' || secret[i] == 'e' || secret[i] == 'i' || secret[i] == 'o' || secret[i] == 'u') {
			combination(i + 1, pw + secret[i], con, vow + 1);
		}
		// 자음인 경우
		else {
			combination(i + 1, pw + secret[i], con + 1, vow);
		}
	}
}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> secret[i];
	}

	// 사전순 정렬
	sort(secret, secret + C);

	combination(0, "", 0, 0);

	return 0;
}
