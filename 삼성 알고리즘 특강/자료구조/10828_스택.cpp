// 10828_스택.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int s[10000];
int ptr = -1;

int empty() {
	if (ptr == -1) return 1;
	else return 0;
}

void push(int x) {
	s[++ptr] = x;
}

int pop() {
	if (empty()) return -1;
	return s[ptr--];
}

int size() {
	return ptr + 1;
}

int top() {
	if (empty()) {
		return -1;
	}
	else {
		return s[ptr];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (cmd == "top") {
			cout << top() << "\n";
		}
		else if (cmd == "size") {
			cout << size() << "\n";
		}
		else if (cmd == "empty") {
			cout << empty() << "\n";
		}
		else if (cmd == "pop") {
			cout << pop() << "\n";
		}
	}

	return 0;
}
