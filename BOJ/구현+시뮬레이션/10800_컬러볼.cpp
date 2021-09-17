// 10800_컬러볼.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct ball {
	int num; // 공 번호
	int color;
	int size;
	int totalScore;
};

typedef struct colorSize {
	int maxSize; // 현재까지의 최대 크기
	int sum; // 현재까지의 누적값
	int before; // 이전 최대 누적값
};

bool sizeComp(ball a, ball b) {
	// 크기 오름차순 정렬
	return a.size < b.size;
}

bool numComp(ball a, ball b) {
	// 번호순 정렬
	return a.num < b.num;
}

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	vector<ball> balls(n);
	vector<colorSize> colors(n + 1); // 색깔별 누적합
	for (int i = 0; i < n; i++) {
		int c, s;
		cin >> c >> s;
		balls[i] = { i, c, s, 0 };
	}

	// 크기 오름차순 정렬
	sort(balls.begin(), balls.end(), sizeComp);

	int before = 0; // 현재 공 바로 이전까지의 최대값
	int sum = balls[0].size; // 현재까지의 누적합
	colors[balls[0].color].maxSize = balls[0].size;
	colors[balls[0].color].sum = balls[0].size;

	for (int i = 1; i < n; i++) {
		int num = balls[i].color; // 현재 색 번호 (1부터 시작)

		// 이전 공 크기보다 현재가 더 크면 before, sum 갱신
		if (balls[i].size > balls[i - 1].size) {
			before = sum;
		}
		sum += balls[i].size; // 현재까지의 크기 누적

		// 현재 공 크기가 같은 색의 최대 공 크기보다 크면 갱신
		if (balls[i].size > colors[num].maxSize) {
			colors[num].maxSize = balls[i].size;
			colors[num].before = colors[num].sum;
		}
		colors[num].sum += balls[i].size;
		
		// 이전 공과 색이 같을 경우
		if (balls[i].size == balls[i - 1].size) {
			balls[i].totalScore = before - colors[num].before;
		}
		// 이전 공과 색이 다를 경우
		else balls[i].totalScore = sum - colors[num].sum;
	}

	// 번호 오름차순 정렬
	sort(balls.begin(), balls.end(), numComp);
	for (int i = 0; i < n; i++) {
		cout << balls[i].totalScore << "\n";
	}
	return 0;
}
