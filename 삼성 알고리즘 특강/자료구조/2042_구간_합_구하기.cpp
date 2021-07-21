// 2042_구간_합_구하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> seq;
vector<ll> tree;
int s; // 첫 leaf의 인덱스

// tree 만들기
void init() {
	// leaf에 값을 넣기
	for (int i = s, j = 1; i < s + n, j <= n; i++, j++) {
		tree[i] = seq[j];
	}
	// 내부노드 채우기
	for (int i = s - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

ll query(int left, int right, int node, int queryLeft, int queryRight) {
	// 범위 밖 -> 결과에 영향이 없는 값(0) return
	if (left > queryRight || right < queryLeft) return 0;
	// 범위 안 -> 현재 노드 값 return
	else if (left >= queryLeft && right <= queryRight) {
		return tree[node]; 
	}
	// 범위 걸쳐있는 경우
	else {
		int mid = (left + right) / 2;
		ll newLeft = query(left, mid, node * 2, queryLeft, queryRight);
		ll newRight = query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
		return newLeft + newRight;
	}
}

void update(int left, int right, int node, int target, ll diff) {
	// 연관 없는 경우 아무것도 안함
	if (target < left || target > right) return;
	// 연관 있는 경우 -> 현재 노드에 diff를 반영 -> 자식에게 diff 전달
	else {
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
	scanf("%d %d %d", &n, &m, &k);

	seq.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &seq[i]);
	}

	s = 1;
	while (s < n) {
		s *= 2;
	}
	tree.resize(s * 2, 0);

	init();
	for (int i = 0; i < m + k; i++) {
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);

		if (a == 1) { // b번째를 c로 바꾸기
			ll diff = c - tree[s + b - 1];
			update(1, s, 1, b, diff);
		}
		else if (a == 2) { // b부터 c까지의 합
			printf("%lld\n", query(1, s, 1, b, c));
		}
	}

	return 0;
}
