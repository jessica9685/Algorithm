// 13251_조약돌_꺼내기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int m, k, n;
vector<int> stone;
double result;

int main() {
	scanf("%d", &m); // 색상 수
	n = 0; // 총 조약돌 개수
	for (int i = 0; i < m; i++) {
		int cnt;
		scanf("%d", &cnt);
		stone.push_back(cnt);
		n += cnt;
	}
	
	scanf("%d", &k);

	// 색이 하나밖에 없거나 1개만 뽑을 경우 확률은 1
	if (m == 1 || k == 1) result = 1;
	else {
		double sameColor = 0;
		for (int i = 0; i < m; i++) {
			double cases = stone[i];
			for (int j = 1; j < k; j++) {
				cases *= (stone[i] - j);
			}
			sameColor += cases;
		}
		
		double total = 1;
		for (int i = 0; i < k; i++) {
			total *= (n - i);
		}

		result = sameColor / total;
	}

	printf("%.9f", result);
	return 0;
}
