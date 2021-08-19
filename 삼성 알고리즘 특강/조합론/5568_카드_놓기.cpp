// 5568_카드_놓기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> cards;
bool visited[10];
set<int> numbers;

void dfs(int idx, string str) {
	// 마지막 숫자까지 돌았을 때
	if (idx == k) {
		int num = stoi(str);
		numbers.insert(num);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(idx + 1, str + cards[i]);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cards.push_back(s);
	}

	dfs(0, s);

	int ans = numbers.size();
	printf("%d\n", ans);
	return 0;
}
