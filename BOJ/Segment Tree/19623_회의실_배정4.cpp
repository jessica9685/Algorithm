// 19623_회의실_배정4.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct meeting {
	int start, end, num;
	/* 끝나는 시간을 기준으로 오름차순 정렬 */
	bool operator<(meeting m) {
		if (end == m.end) return start < m.start;
		return end < m.end;
	}
};

int N;
meeting m[100000];
vector<int> compress;
// 회의 시작시간 ~ 끝시간 동안의 최대 참여 인원수 세그먼트 트리
int seg[600000]; // mlogn

int find(int time) {
	/* 부분 구간 인덱스 */
	int start = 0;
	int end = compress.size() - 1;
	int mid;

	while (start < end) {
		mid = (start + end) / 2;
		if (compress[mid] == time) return mid;
		if (compress[mid] > time) end = mid - 1;
		else start = mid + 1;
	}
}

/* [start, end] 구간에서 idx까지 회의에 참여할 수 있는 인원의 최대값 */
// pos: update할 노드 번호
void update(int start, int end, int node, int pos, int num) {
	if(start >= pos){
		seg[node] = max(seg[node], num);
		return;
	}
	if (end < pos) return;
	 
	int mid = (start + end) / 2;
	update(start, mid, node * 2, pos, num);
	update(mid + 1, end, node * 2 + 1, pos, num);
}

int ret(int start, int end, int node, int pos) {
	// 구간을 벗어난 경우
	if (start > pos || end < pos) return 0;
	
	if (start == end) return seg[node];
	int mid = (start + end) / 2;

	return max(seg[node], max(ret(start, mid, node * 2, pos), ret(mid + 1, end, node * 2 + 1, pos)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> m[i].start >> m[i].end >> m[i].num;
		compress.push_back(m[i].start);
		compress.push_back(m[i].end);
	}

	// 회의 끝나는 시간 기준 정렬
	sort(m, m + N);
	// 좌표 압축
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int sum = ret(0, compress.size(), 1, find(m[i].start));
		answer = max(answer, sum + m[i].num);
		update(0, compress.size(), 1, find(m[i].end), sum + m[i].num);
	}

	cout << answer << endl;
}
