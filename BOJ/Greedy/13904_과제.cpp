// 13904_과제.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct work {
	int day;
	int score;
};

bool comp(work a, work b) {
	if (a.score == b.score) {
		return a.day < b.day;
	}
	// 점수 내림차순 정렬
	return a.score > b.score;
}

int n;
work works[1001];
int check[1001] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int maxDeadline = 0;
	for (int i = 1; i <= n; i++) {
		int d, w;
		cin >> d >> w;
		works[i] = { d, w };
		if (maxDeadline < d) maxDeadline = d;
	}

	// 점수 내림차순 정렬
	sort(works + 1, works + n + 1, comp);

	for (int i = 1; i <= n; i++) {
		// 마감일에 한 과제가 없는 경우
		if (check[works[i].day] == 0) {
			// 과제 수행
			check[works[i].day] = works[i].score;
		}
		// 이미 마감일에 과제를 한 경우
		else {
			int deadline = works[i].day - 1;
			// 과제 배정이 안된 곳을 발견할 때까지 일수를 1씩 감소시킴
			while (deadline >= 1) {
				if (check[deadline] == 0) {
					check[deadline] = works[i].score;
					break;
				}
				deadline--;
			}
		}
	}

	int maxScore = 0;
	for (int i = 1; i <= maxDeadline; i++) maxScore += check[i];

	cout << maxScore << "\n";
	return 0;
}
