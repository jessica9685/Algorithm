// 10845_큐.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int q[10000];
int s, e; // e는 마지막 빈 자리

int size() {
	return e - s;
}

int empty() {
	if (size() == 0) return 1;
	else return 0;
}

void push(int x) {
	q[e++] = x;
}

int pop() {
	if (empty()) return -1;
	else {
		return q[s++];
	}
}

int front() {
	if (empty()) {
		return -1;
	}
	else {
		return q[s];
	}
}

int back() {
	if (empty()) {
		return -1;
	}
	else {
		return q[e - 1];
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
		else if (cmd == "front") {
			cout << front() << "\n";
		}
		else if (cmd == "back") {
			cout << back() << "\n";
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
