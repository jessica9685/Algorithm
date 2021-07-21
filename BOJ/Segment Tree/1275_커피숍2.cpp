// 1275_커피숍2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q; 
int s; // 첫 leaf node의 인덱스
vector<ll> seq;
vector<ll> tree;

// 트리 생성
void init() {
	// leaf 삽입
	for (int i = 0; i < n; i++) {
		tree[s + i] = seq[i];
	}
	// 내부노드 삽입
	for (int i = s - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

ll query(int left, int right, int node, int queryLeft, int queryRight) {
	// 범위 밖일 때
	if (left > queryRight || right < queryLeft) return 0;
	// 범위 안일 때
	else if ((left >= queryLeft) && (right <= queryRight)) {
		return tree[node];
	}
	// 범위가 걸쳐있을 때
	else {
		int mid = (left + right) / 2;
		ll leftSum = query(left, mid, node * 2, queryLeft, queryRight);
		ll rightSum = query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
		return leftSum + rightSum;
	}
}

void update(int left, int right, int node, int target, ll diff) {
	// target과 연관이 없는 경우 -> 아무것도 안함
	if ((target < left) || (target > right)) return;
	// target과 연관이 있는 경우
	else {
		// 현재 노드에 diff를 반영
		tree[node] += diff;
		// 내부노드일 때 (자식 노드가 존재할 때)
		if (left != right) {
			int mid = (left + right) / 2;
			update(left, mid, node * 2, target, diff);
			update(mid + 1, right, node * 2 + 1, target, diff);
		}
	}
}

int main() {
	scanf("%d %d", &n, &q);
	seq.resize(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &seq[i]);
	}

	s = 1;
	while (s < n) {
		s *= 2;
	}
	tree.resize(s * 2);

	init(); // 초기화
	for (int i = 0; i < q; i++) {
		int x, y, a;
		ll b;
		scanf("%d %d %lld %lld", &x, &y, &a, &b);

		// x ~ y까지의 합 구하기
		if (x <= y) printf("%lld\n", query(1, s, 1, x, y));
		else printf("%lld\n", query(1, s, 1, y, x));
		
		// a번째 수를 b로 바꾸기
		ll diff = b - tree[s + a - 1];
		update(1, s, 1, a, diff);
	}

	return 0;
}
