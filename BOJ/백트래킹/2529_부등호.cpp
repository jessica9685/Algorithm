// 2529_부등호.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int k;
char sign[10]; // 부등호
bool visited[10]; // 숫자 선택 여부
vector<string> answer; // 조건을 만족하는 순열들
vector<int> seq; // 생성된 순열

// 만들어진 수열이 부등호와 일치하면 true
bool is_possible() {
	for (int i = 0; i < k; i++) {
		if (sign[i] == '<') {
			if (seq[i] > seq[i + 1]) {
				return false;
			}
		}
		else if (sign[i] == '>') {
			if (seq[i] < seq[i + 1]) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int cnt) {
	if (cnt == k + 1) {
		if (is_possible()) {
			string ans;
			for (int i = 0; i < k + 1; i++) {
				ans += to_string(seq[i]);
			}
			answer.push_back(ans);
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		seq.push_back(i);
		dfs(cnt + 1);
		visited[i] = false;
		seq.pop_back();
	}
}

int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf(" %c", &sign[i]);
	}

	dfs(0);

	sort(answer.begin(), answer.end());

	// 최대값 출력
	cout << answer[answer.size() - 1] << endl;
	// 최소값 출력
	cout << answer[0] << endl;
	return 0;
}
