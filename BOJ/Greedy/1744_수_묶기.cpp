// 1744_수_묶기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
int ans;

// 내림차순 정렬
bool comp(int a, int b) {
	return a > b;
}

int maxSum(vector<int> arr) {
	int i = 0;
	int s = arr.size();
	int result = 0;

	while (i <= s - 3) {
		/* 1이 있는 경우 x보다 +한 값이 더 클 수 있음 */
		result += max(arr[i] + arr[i + 1], arr[i] * arr[i + 1]);
		i += 2;
	}

	// size가 짝수인 경우
	if (s % 2 == 0) {
		result += max(arr[s - 1] + arr[s - 2], arr[s - 1] * arr[s - 2]);
	}
	// size가 홀수인 경우
	else result += arr[s - 1];

	return result;
}

int main() {
	scanf("%d", &n);

	vector<int> minusArr; // 음수 배열 (0 포함)
	vector<int> plusArr; // 양수 배열

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		
		if (num <= 0) minusArr.push_back(num);
		else plusArr.push_back(num);
	}

	// 음수가 없을 때 (양수만 존재)
	if (minusArr.size() == 0) {
		// 내림차순 정렬 (양수)
		sort(plusArr.begin(), plusArr.end(), comp);
		ans = maxSum(plusArr);
	}
	// 양수가 없을 때 (음수만 존재)
	else if (plusArr.size() == 0) {
		// 오름차순 정렬 (음수)
		sort(minusArr.begin(), minusArr.end());
		ans = maxSum(minusArr);
	}
	// 음수, 양수가 둘 다 존재할 때
	else {
		// 내림차순 정렬 (양수)
		sort(plusArr.begin(), plusArr.end(), comp);
		// 오름차순 정렬 (음수)
		sort(minusArr.begin(), minusArr.end());
		ans = maxSum(minusArr) + maxSum(plusArr);
	}

	printf("%d\n", ans);
	return 0;
}
