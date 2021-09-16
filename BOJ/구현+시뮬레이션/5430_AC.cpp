// 5430_AC.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		string p; // 명령어
		cin >> p;
		int n; // 배열 길이
		cin >> n;
		string arr; // 배열
		cin >> arr;

		deque<int> dq;
		int i = 1;
		while (arr[i] != '\0') {
			int num = 0;
			while (arr[i] >= '0' && arr[i] <= '9') {
				num *= 10;
				num += (int)(arr[i] - '0');
				i++;
			}
			if(num != 0) dq.push_back(num);
			i++;
		}

		bool error = false;
		int cntR = 0; // R 명령어 횟수
		// R 명령이 나올 때마다 reverse 함수를 쓰면 시간초과 (reverse의 시간복잡도 O(n))
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'D') {
				if (dq.empty()) {
					error = true;
					break;
				}
				else {
					// R 명령 횟수가 짝수이면 앞에서 pop
					if (cntR % 2 == 0) dq.pop_front();
					// 홀수이면 뒤에서 pop
					else dq.pop_back();
				}
			}
			else if (p[j] == 'R') cntR++;
		}

		if (error) cout << "error\n";
		else {
			// R 명령 횟수가 홀수이면 reverse 수행
			if (cntR % 2 != 0) reverse(dq.begin(), dq.end());
			string res = "[";
			for (int i = 0; i < dq.size(); i++) {
				res += to_string(dq[i]);
				if (i < dq.size() - 1) res.push_back(',');
			}
			res.push_back(']');
			cout << res << "\n";
		}
	}
	return 0;
}
