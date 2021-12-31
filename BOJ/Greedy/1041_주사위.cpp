// 1041_주사위.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll dice[6];
ll ans;

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < 6; i++) scanf("%lld", &dice[i]);
	if (n == 1) { // 주사위가 1개일 때
		sort(dice, dice + 6);
		for (int i = 0; i < 5; i++) ans += dice[i];
	}
	else { // 2개 이상일 때
		// 각 마주보는 면의 최솟값
		dice[0] = min(dice[0], dice[5]);
		dice[1] = min(dice[1], dice[4]);
		dice[2] = min(dice[2], dice[3]);

		sort(dice, dice + 3); // A, B, C 오름차순 정렬
		// 인접한 세 면의 최소값
		ll min3 = dice[0] + dice[1] + dice[2];
		// 인접한 두 면의 최소값
		ll min2 = dice[0] + dice[1];
		ll min1 = dice[0]; // 한 면의 최소값

		ll n1 = 0; // 1면 보이는 주사위 수
		ll n2 = 0; // 2면
		ll n3 = 4; // 3면

		n1 = (n - 1) * (n - 2) * 4 + (n - 2) * (n - 2);
		n2 = (n - 1) * 4 + (n - 2) * 4;

		ans += n1 * min1;
		ans += n2 * min2;
		ans += n3 * min3;
	}
	printf("%lld\n", ans);
	return 0;
}
