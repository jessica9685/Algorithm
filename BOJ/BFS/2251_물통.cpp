// 2251_물통.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 200

int A, B, C;
set<int> remain;
bool visited[MAX][MAX][MAX] = { false, };

typedef struct Bottle {
	int a, b, c;
};

void bfs() {
	queue<Bottle> q;
	q.push({ 0, 0, C });
	
	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		// 이미 방문했으면 패스
		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;

		// A 물통이 비어있으면 C에 남아있는 물 저장
		if (a == 0) remain.insert(c);

		// A -> B
		if (a + b <= B) q.push({ 0, a + b, c });
		else q.push({ a + b - B, B, c });

		// A -> C
		if (a + c <= C) q.push({ 0, b, a + c });
		else q.push({ a + c - C, b, C });

		// B -> A
		if (b + a <= A) q.push({ b + a, 0, c });
		else q.push({ A, b + a - A, c });

		// B -> C
		if (b + c <= C) q.push({ a, 0, b + c });
		else q.push({ a, b + c - C, C });

		// C -> A
		if (c + a <= A) q.push({ c + a, b, 0 });
		else q.push({ A, b, c + a - A });

		// C -> B
		if (c + b <= B) q.push({ a, c + b, 0 });
		else q.push({ a, B, c + b - B });
	}
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	bfs();
	for (auto w : remain) {
		printf("%d ", w);
	}
	printf("\n");
	return 0;
}
