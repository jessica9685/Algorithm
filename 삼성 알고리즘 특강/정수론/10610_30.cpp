// 10610_30.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string N;

// 내림차순 정렬
bool comp(char a, char b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N; // string 형태로 입력받음 (N의 자리수는 100000)
	int s = N.size();

	// 30의 배수이려면 
	// 1) 각 자리수의 합이 3의 배수
	// 2) 0을 반드시 포함
	bool isThree = false;
	bool isZero = false;
	int sum = 0;
	for (int i = 0; i < s; i++) {
		sum += (N[i] - '0');
		if (N[i] == '0') isZero = true;
	}
	if (sum % 3 == 0) isThree = true;

	// 각 자리수의 합이 3의 배수가 아니거나 0이 없으면 -1
	if (!isThree || !isZero) printf("-1\n");
	else {
		vector<char> num;
		for (int i = 0; i < s; i++) num.push_back(N[i]);

		// 내림차순 정렬
		sort(num.begin(), num.end(), comp);

		// 정렬된 순서대로 answer에 push
		string ans = "";
		for (int i = 0; i < s; i++) ans.push_back(num[i]);
		
		cout << ans << "\n";
	}
	return 0;
}
