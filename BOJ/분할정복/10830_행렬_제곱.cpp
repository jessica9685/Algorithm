// 10830_행렬_제곱.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, B;
ll A[5][5], temp[5][5], answer[5][5];

void mul(ll a[][5], ll b[][5]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				temp[i][j] += (a[i][k] * b[k][j]);
			}
			temp[i][j] %= 1000;
		}
	}

	// 계산 결과를 a에 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[i][j];
		}
	}
}

int main() {
	cin >> n >> B;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lld", &A[i][j]);
		}
		// 정답 행렬은 단위 행렬로 초기화
		answer[i][i] = 1; 
	}

	while (B > 0) {
		// 거듭제곱수가 홀수이면
		if (B % 2 == 1) {
			mul(answer, A); // A 한번 곱하기
		}
		B /= 2;
		mul(A, A); // 제곱
	}

	// 정답 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%lld ", answer[i][j]);
		}
		printf("\n");
	}
	return 0;
}
