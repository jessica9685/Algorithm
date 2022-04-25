// 2504_괄호의_값.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

string str;
int ans;
stack<char> s;
bool isRight = true;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> str;

	int temp = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		else {
			// 스택이 비어있으면 올바르지 않은 괄호
			if (s.empty()) {
				isRight = false;
				break;
			}
			else {
				if (s.top() == '(' && str[i] == ')') {
					// 겹쳐진 괄호가 아니면
					if (str[i - 1] == '(') ans += temp;
					temp /= 2;
				}
				else if (s.top() == '[' && str[i] == ']') {
					if (str[i - 1] == '[') ans += temp;
					temp /= 3;
				}
				// 괄호의 짝이 맞지 않으면 올바르지 않은 괄호
				else {
					isRight = false;
					break;
				}
				s.pop();
			}
		}
	}
	// 스택이 비어있지 않으면 올바르지 않은 괄호문
	if (!s.empty()) isRight = false;
	
	if (!isRight) ans = 0;
	printf("%d\n", ans);
	return 0;
}
