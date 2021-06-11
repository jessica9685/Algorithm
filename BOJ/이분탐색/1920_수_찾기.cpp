// 1920_수_찾기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n, m;
vector<int> arr;

int find(int cmd) {
	int answer = 0;
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] >= cmd) {
			if (arr[mid] == cmd) {
				answer = 1;
				break;
			}
			else {
				right = mid - 1;
			}
		}
		else { // arr[mid] < cmd
			left = mid + 1;
		}
	}

	return answer;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());

	scanf("%d", &m);
	while (m--) {
		int cmd;
		scanf("%d", &cmd);
		printf("%d\n", find(cmd));
	}

	return 0;
}
