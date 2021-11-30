// 2212_센서.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, k; // k: 집중국의 개수 == 구간의 개수라고 생각하면 편함
vector<int> sensor;

int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	sensor.resize(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sensor[i]);
	}

	// 센서 오름차순 정렬
	sort(sensor.begin(), sensor.end());

	// 각 센서간 거리 차이 저장
	vector<int> diff(n - 1, 0);
	for (int i = 0; i < n - 1; i++) {
		diff[i] = sensor[i + 1] - sensor[i];
	}

	// 거리차이 오름차순 정렬
	sort(diff.begin(), diff.end());

	int answer = 0; // 수신가능영역 거리 합
	// 기지국의 개수: n, 집중국의 개수: k
	// 수신받는 기지국 수는? n - k개
	// n - k 개 기지국의 수신거리를 구하면 됨
	for (int i = 0; i < n - k; i++) {
		answer += diff[i];
	}
	printf("%d\n", answer);
	return 0;
}
