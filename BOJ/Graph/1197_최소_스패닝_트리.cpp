// 1197_최소_스패닝_트리.cpp
// 크루스칼 알고리즘
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#define MAX 10000 + 1

int v; // 정점의 개수
int e; // 간선의 개수
int U[MAX];

void initial(int n) { // n개의 서로소 부분집합 초기화
	for (int i = 1; i <= n; i++) {
		U[i] = i;
	}
}

int find(int x) { // x가 속한 집합 찾기
	if (U[x] == x) return x;
	else return U[x] = find(U[x]);
}

bool equal(int p, int q) { // p, q가 같은 집합인지 확인하는 함수
	if (p == q) return true;
	else return false;
}

void merge(int p, int q) { // 서로 다른 집합 p, q를 같은 집합으로 합치기
	if (p < q) U[q] = p; // (가중치가 더 작은 집합에 속하도록) 작은 값으로 바꿔줌 
	else U[p] = q;
}

int main()
{
	int min_path = 0;

	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;

	vector<pair<int, pair<int, int>>> g;

	for (int i = 0; i < e; i++) {
		int v1, v2; // 간선을 이루는 정점 2개
		int w; // 가중치
		cin >> v1 >> v2 >> w;
		g.push_back(make_pair(w, make_pair(v1, v2)));
	}

	sort(g.begin(), g.end()); // 가중치 기준 오름차순 정렬
	
	initial(v); // 집합 초기화

	for (int i = 0; i < e; i++) {
		int p, q, w;
		p = find(g[i].second.first);
		q = find(g[i].second.second);
		w = g[i].first;
		if (!equal(p, q)) {
			merge(p, q);
			min_path += w;
		}
	}
	cout << min_path << endl;
}
