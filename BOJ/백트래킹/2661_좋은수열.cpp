// 2661_좋은수열.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 16

int N;
string num;

// 반복되는 문자열 검증
bool is_good() {
	int len = num.size();

	// i: 비교할 수열의 길이
	for (int i = 1; i <= len / 2; i++) {
		string x = num.substr(len - i, i);
		string y = num.substr(len - (i * 2), i);

		// 나쁜 수열이면 false
		if (x == y) return false;
	}

	return true;
}

void permutation(int cnt) {
	if (cnt == N) {
		cout << num << endl;
		exit(0); // 종료
	}

	// 1부터 3까지 차례로 넣어보고
	// 좋은 수열이면 재귀
	for (int i = 1; i <= 3; i++) {
		num.push_back(i + '0');
		if (is_good()) {
			permutation(cnt + 1);
		}
		
		num.pop_back();
	}
}

int main() {
	cin >> N;

	permutation(0);

	return 0;
}
