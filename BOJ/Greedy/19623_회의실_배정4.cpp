// 19623_회의실_배정4.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> schedule;
int N;
vector<schedule> meeting;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end, people;
		cin >> start >> end >> people;
		meeting.push_back(make_tuple(start, end, people));
	}
	
	// start 기준으로 오름차순 정렬
	// start가 같으면 end 오름차순 정렬
	sort(meeting.begin(), meeting.end());

	// first: end, second: 종료 시간까지의 최대 인원 수
	// 회의 종료 시간 기준 오름차순 정렬
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int answer = 0;
	int prev = 0;
	for (int i = 0; i < N; i++) {
		int curStart = get<0>(meeting[i]);
		int curEnd = get<1>(meeting[i]);
		int curPeople = get<2>(meeting[i]);

		while (!pq.empty() && pq.top().first < curStart) {
			prev = max(prev, pq.top().second);
			pq.pop();
		}
		pq.push({ curEnd, prev + curPeople });
		answer = max(answer, prev + curPeople);
	}

	cout << answer << endl;
}
