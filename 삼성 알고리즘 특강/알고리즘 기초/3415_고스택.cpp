// 3415_고스택.cpp
#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;

typedef struct cmd {
	string com;
	ll p;
};

vector<cmd> commands;
stack<ll> s;
vector<vector<string>> result;
bool errorFlag = false;
ll MAX = 1000000000;

void inv() {
	if (s.empty()) {
		errorFlag = true;
		return;
	}

	ll top = s.top();
	s.pop();
	s.push(-top);
}

void dup() {
	if (s.empty()) {
		errorFlag = true;
		return;
	}

	ll top = s.top();
	s.push(top);
}

void swp() {
	if (s.size() < 2) {
		errorFlag = true;
		return;
	}

	ll first = s.top();
	s.pop();
	ll second = s.top();
	s.pop();

	s.push(first);
	s.push(second);
}

void add() {
	if (s.size() < 2) {
		errorFlag = true;
		return;
	}

	ll first = s.top();
	s.pop();
	ll second = s.top();
	s.pop();

	if (abs(second + first) > MAX) errorFlag = true;
	else s.push(second + first);
}

void sub() {
	if (s.size() < 2) {
		errorFlag = true;
		return;
	}

	ll first = s.top();
	s.pop();
	ll second = s.top();
	s.pop();

	if (abs(second - first) > MAX) errorFlag = true;
	else s.push(second - first);
}

void mul() {
	if (s.size() < 2) {
		errorFlag = true;
		return;
	}

	ll first = s.top();
	s.pop();
	ll second = s.top();
	s.pop();

	if (abs(second * first) > MAX) errorFlag = true;
	else s.push(second * first);
}

void div() {
	if (s.size() < 2 || s.top() == 0LL) {
		errorFlag = true;
		return;
	}

	ll first = s.top();
	s.pop();
	ll second = s.top();
	s.pop();

	if (abs(second / first) > MAX) errorFlag = true;
	else s.push(second / first);
}

void mod() {
	if (s.size() < 2 || s.top() == 0LL) {
		errorFlag = true;
		return;
	}

	ll first = s.top();
	s.pop();
	ll second = s.top();
	s.pop();

	if (abs(second % first) > MAX) errorFlag = true;
	else s.push(second % first);
}

void exec(cmd c) {
	if (c.com == "NUM") s.push(c.p);
	else if (c.com == "POP") {
		if (s.empty()) errorFlag = true;
		else s.pop();
	}
	else if (c.com == "INV") inv();
	else if (c.com == "DUP") dup();
	else if (c.com == "SWP") swp();
	else if (c.com == "ADD") add();
	else if (c.com == "SUB") sub();
	else if (c.com == "MUL") mul();
	else if (c.com == "DIV") div();
	else if (c.com == "MOD") mod();
}

void clear() {
	while (!s.empty()) s.pop();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		commands.clear();
		while (true) {
			cmd c;
			cin >> c.com;
			if (c.com == "NUM") cin >> c.p;
			else if (c.com == "QUIT") return 0; // 종료
			else c.p == 0;

			commands.push_back(c);
			if (c.com == "END") break;
		}

		int n;
		cin >> n;

		while (n--) {
			if (!s.empty()) clear(); // 스택 비우기
			errorFlag = false;
			ll x;
			cin >> x;
			s.push(x);

			for (int i = 0; i < (int)commands.size(); i++) {
				if (commands[i].com == "END") break;
				else {
					exec(commands[i]);
					if (errorFlag) break;
				}
			}

			if (errorFlag || s.size() != 1) {
				cout << "ERROR\n";
			}
			else cout << s.top() << "\n";
		}
		cout << "\n";
	}
}
