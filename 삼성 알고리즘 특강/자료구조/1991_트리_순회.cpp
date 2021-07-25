// 1991_트리_순회.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

struct node {
	char left, right;
};

int n; // 노드 개수
node tree[27];

// 전위 순회
void preOrder(char root) {
	if (root == '.') return;
	cout << root;
	preOrder(tree[root - 'A'].left);
	preOrder(tree[root - 'A'].right);
}

// 중위 순회
void inOrder(char root) {
	if (root == '.') return;
	inOrder(tree[root - 'A'].left);
	cout << root;
	inOrder(tree[root - 'A'].right);
}

// 후위 순회
void postOrder(char root) {
	if (root == '.') return;
	postOrder(tree[root - 'A'].left);
	postOrder(tree[root - 'A'].right);
	cout << root;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while (n--) {
		char a, b, c;
		cin >> a >> b >> c;
		
		tree[a - 'A'].left = b;
		tree[a - 'A'].right = c;
	}

	preOrder('A');
	cout << "\n";
	inOrder('A');
	cout << "\n";
	postOrder('A');

	return 0;
}
