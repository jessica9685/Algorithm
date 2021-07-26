// 1717_집합의_표현.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 51

int n, m;
vector<int> parent;

// 부모 찾기
int find(int a) {
	if (parent[a] == a) return a;
	else {
		return parent[a] = find(parent[a]);
	}
}

// 합집합
void unionSet(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	parent[pa] = pb;
  // parent[pb] = pa; 도 가능
}

int main() {
	scanf("%d %d", &n, &m);

	// parent 초기화
	parent.resize(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);
		// 합집합
		if (cmd == 0) {
			unionSet(a, b);
		}
		// 같은 집합인지 확인
		else if (cmd == 1) {
			if (find(a) == find(b)) {
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}


	return 0;
}
