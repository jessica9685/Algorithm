// 1722_순열의_순서.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int num;
ll k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> num;

	// 팩토리얼 값 초기화
	vector<ll> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
	}

	// 선택된 숫자면 true
	vector<bool> visited(n + 1, false);

	// k번째 순열 찾기
	if (num == 1) {
		cin >> k;
		vector<int> ans(n);

		for (int i = 0; i < n; i++) { // i개 숫자 선택
			for (int j = 1; j <= n; j++) { // 숫자 j를 선택
				// 이미 순열에 존재할 경우 넘어감
				if (visited[j]) continue;
				// k가 팩토리얼보다 크면 범위 밖임
				if (fact[n - i - 1] < k) {
					k -= fact[n - i - 1];
				}
				// k가 팩토리얼 값보다 크면 범위 내에 해당 숫자가 존재한다는 뜻
				else {
					ans[i] = j;
					visited[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) cout << ans[i] << " ";
		cout << "\n";
	}
	// 주어진 순열이 몇 번째인지?
	else if (num == 2) {
		vector<int> seq(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> seq[i];
		}

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < seq[i]; j++) {
				// 1부터 해당 숫자까지의 경우의 수 더해줌
				// 1XXX, 2XXX, 3XXX... -> += 3!
				if (!visited[j]) {
					ans += fact[n - i - 1];
				}
			}
			visited[seq[i]] = true;
		}

		cout << ans + 1 << "\n";
	}

	return 0;
}
