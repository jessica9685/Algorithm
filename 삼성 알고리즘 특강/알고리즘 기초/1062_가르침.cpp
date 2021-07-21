// 1062_가르침.cpp
// 다른 방법 - 비트마스킹
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> words;
int alphabet[26];
int answer;

// 단어 읽을 수 있으면 true
bool canRead(string str) {
	for (auto l : str) {
		int idx = l - 'a';
		if (alphabet[idx] == 0) return false;
	}
	return true;
}

void dfs(int idx, int cnt) {
	if (cnt == k) {
		int tmp = 0;
		for (auto word : words) {
			if (canRead(word)) tmp++;
		}
		answer = max(answer, tmp);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (!alphabet[i]) {
			alphabet[i] = 1;
			dfs(i, cnt + 1);
			alphabet[i] = 0;
		}
	}

}

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s.substr(4, s.length() - 4);
		words.push_back(s);
	}

	if (k < 5) answer = 0;
	else if (k == 26) answer = n;
	else {
		alphabet[0] = 1; // a
		alphabet[2] = 1; // c
		alphabet[8] = 1; // i
		alphabet[13] = 1; // n
		alphabet[19] = 1; // t
		k -= 5;
		dfs(0, 0);
	}

	printf("%d\n", answer);
}
