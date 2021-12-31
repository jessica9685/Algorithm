// 1092_배.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int n, m;
vector<int> crane;
vector<int> box;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int w;
		scanf("%d", &w);
		crane.push_back(w);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int b;
		scanf("%d", &b);
		box.push_back(b);
	}
	
	// 오름차순 정렬
	sort(crane.begin(), crane.end());
	sort(box.begin(), box.end());

	// 무게제한을 초과하는 박스가 있으면 -1
	if (box[m - 1] > crane[n - 1]) {
		printf("-1\n");
		return 0;
	}

	// 각 크레인이 옮길 수 있는 박스의 수
	int avail[51] = { 0, };
	int idx = 0;
	for (int i = 0; i < m; i++) {
		if (crane[idx] >= box[i]) avail[idx]++;
		else {
			idx++;
			i--;
		}
	}

	// cnt: 옮겨진 박스의 수
	int cnt = 0, ans = 0;
	while (true) {
		// 가장 무거운 크레인부터 옮기기
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j >= 0; j--) {
				if (avail[j] > 0) {
					avail[j]--;
					cnt++;
					break;
				}
			}
			if (cnt == m) break;
		}
		ans++; // 시간 증가
		if (cnt == m) break; // 모든 박스를 다 옮기면 break
	}

	printf("%d\n", ans);
	return 0;
}
