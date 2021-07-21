// 1202_보석_도둑.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 300000

typedef long long ll;
typedef struct gem {
	int weight;
	int value;
};

bool compWeight(gem a, gem b) {
	return a.weight < b.weight;
}

int n; // 보석 개수
int k; // 가방 개수

int main() {
	scanf("%d %d", &n, &k);

	vector<gem> gems;
	for (int i = 0; i < n; i++) {
		gem g;
		scanf("%d %d", &g.weight, &g.value);
		gems.push_back(g);
	}
	sort(gems.begin(), gems.end(), compWeight); // 무게 오름차순 정렬

	vector<int> bags;
	for (int i = 0; i < k; i++) {
		int bag;
		scanf("%d", &bag);
		bags.push_back(bag);
	}
	sort(bags.begin(), bags.end()); // 무게 오름차순 정렬

	priority_queue<int> pq;
	ll result = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		// 해당 가방에 넣을 수 있는 보석들 큐에 push
		while (idx < n && gems[idx].weight <= bags[i]) {
			pq.push(gems[idx++].value);
		}

		// 가방에 들어갈 수 있는 보석이 있다면
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	printf("%lld\n", result);
	return 0;
}
