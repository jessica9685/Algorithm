// 12904_A와_B.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string before, after;

int main() {
	cin >> before;
	cin >> after;

	// after을 before로 만들 수 있는지 확인
	// 주어진 연산을 거꾸로 수행
	while (after.size() > 0) {
		// 길이가 같아지면 break
		if (before.size() == after.size()) break;

		int s = after.size();
		// 1. 뒤에 B를 빼고 뒤집는다
		if (after[s - 1] == 'B') {
			after.pop_back();
			reverse(after.begin(), after.end());
		}
		// 2. 뒤에 A를 뺀다
		else {
			after.pop_back();
		}
	}

	if (before == after) printf("1\n");
	else printf("0\n");
	return 0;
}

