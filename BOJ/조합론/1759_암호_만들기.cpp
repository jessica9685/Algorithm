// 1759_암호_만들기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> alphabet;

// 모음이면 true
bool aeiou(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
		return true;
	}
	else return false;
}

// c: 자음, v: 모음
void dfs(int idx, int c, int v, string str) {
	// 문자 다 고르면 종료
	if (str.size() == L) {
		// 자음 2개 미만 or 모음 없는 경우
		if (c < 2 || v < 1) return;
		else cout << str << "\n";
	}

	for (int i = idx; i < C; i++) {
		// 모음이면
		if (aeiou(alphabet[i])) dfs(i + 1, c, v + 1, str + alphabet[i]);
		// 자음이면
		else dfs(i + 1, c + 1, v, str + alphabet[i]);
	}
}

int main() {
	scanf("%d %d", &L, &C);

	for (int i = 0; i < C; i++) {
		char ch;
		scanf(" %c", &ch);
		alphabet.push_back(ch);
	}

	// 알파벳 순서대로 정렬
	sort(alphabet.begin(), alphabet.end()); 
	dfs(0, 0, 0, "");
}
