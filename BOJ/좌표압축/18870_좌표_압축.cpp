// 18870_좌표_압축.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX 1000001

int n;
/* 
	좌표 압축: 해당 좌표의 값을 그 값보다 작은 좌표값들의 개수로 대체
*/

int main() {
	scanf("%d", &n); 
	vector<pair<int, int>> num;
	vector<int> ans(MAX);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		num.push_back({ x, i }); // 좌표, 인덱스
	}
	
	sort(num.begin(), num.end()); // 오름차순 정렬

	int cnt = 0;
	int pivot = num[0].first;
	ans[num[0].second] = 0; // 최솟값 = 0

	for (int i = 1; i < n; i++) {
		if (pivot == num[i].first) {
			ans[num[i].second] = cnt;
		}
		else {
			ans[num[i].second] = ++cnt;
			pivot = num[i].first;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

