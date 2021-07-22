// 2243_사탕상자.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

typedef long long ll;

int n, m, k;
vector<ll> seq;
vector<ll> tree;
int s; // leaf의 개수 (첫 leaf의 인덱스)

/* Top-Down 방식 */
ll query(int left, int right, int node, int cnt) {
	// 원하는 사탕을 찾았을 경우(리프를 찾을 경우)
	if (left == right) {
		return left;
	}
	int mid = (left + right) / 2;
	// 왼쪽 자식이 cnt를 포함할 때
	if (tree[node * 2] >= cnt) {
		return query(left, mid, node * 2, cnt);
	}
	// 오른쪽 자식이 cnt를 포함할 때
	else {
		cnt -= tree[node * 2];
		return query(mid + 1, right, node * 2 + 1, cnt);
	}
}

void update(int left, int right, int node, int target, ll diff) {
	if(left <= target && target <= right) {
		tree[node] += diff;
		// 내부노드일 때(자식이 있을 때) (left != right)
		if (left != right) {
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target, diff);
			update(mid + 1, right, node * 2 + 1, target, diff);
		}
	}
}


int main() {
	scanf("%d", &n);

	s = 1;
	while (s < MAX) {
		s *= 2;
	}
	tree.resize(s * 2, 0);

	for (int i = 0; i < n; i++) {
		int a;
		ll b, c;
		scanf("%d", &a);
		if (a == 1) { // b번째 사탕 빼기
			scanf("%lld", &b);
			ll flavor = query(1, s, 1, b);
			printf("%lld\n", flavor);
			update(1, s, 1, flavor, -1);
		}
		else if (a == 2) { // b맛 사탕 c개 넣기
			scanf("%lld %lld", &b, &c);
			update(1, s, 1, b, c);
		}

	}
	return 0;
}
