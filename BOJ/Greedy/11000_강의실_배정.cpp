// 11000_강의실_배정.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX 100001

struct endAsc {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

bool startAsc(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> lecture;
	for (int i = 0; i < n; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		lecture.push_back({ start, end });
	}

	/* 강의가 시작하는 시간 기준 오름차순 정렬 */
	sort(lecture.begin(), lecture.end(), startAsc);

	int classNum = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, endAsc> pq;
	pq.push(lecture[0]);
	for (int i = 1; i < n; i++) {
		// 현재 강의가 끝나는 시간 <= 다음 강의 시작 시간 (겹칠 때)
		if (pq.top().second <= lecture[i].first) {
			pq.pop();
		}
		pq.push(lecture[i]);
	}

	classNum = pq.size();
	printf("%d\n", classNum);
}

