// 2042_구간_합_구하기.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> seq;
vector<ll> tree;
int s; // 첫 leaf의 인덱스 (leaf의 개수)

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

/* Top-Down 방식 */
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

/* Bottom-Up 방식 */
void updateBU(int target, ll value) {
	// leaf에서 target을 찾음
	int node = s + target - 1;
	// value 변경
	tree[node] = value;
	// root에 도달할 때까지 부모에 값 반영
	node /= 2;
	while (node > 0) {
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		node /= 2;
	}
}

ll queryBU(int queryLeft, int queryRight) {
	// leaf에서 left, right 설정
	int left = s + queryLeft - 1;
	int right = s + queryRight - 1;
	ll sum = 0;
	while (left <= right) { // equal 반드시 포함
		// left node가 홀수이면 현재 노드값 사용하고 한칸 옆으로
		// 자식 하나만 query 범위에 포함될 경우
		if (left % 2 == 1) {
			sum += tree[left++];
		}
		// right node가 짝수(왼쪽자식)이면 현재 노드값 사용하고 한칸 옆으로
		// 자식 하나만 query 범위에 포함될 경우
		if (right % 2 == 0) {
			sum += tree[right--];
		}
		// left, right 모두 부모로 이동
		left /= 2;
		right /= 2;
	}

	return sum;
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
