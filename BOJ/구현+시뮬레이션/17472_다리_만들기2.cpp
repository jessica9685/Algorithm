// 17472_다리_만들기2.cpp
// 크루스칼
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 13
#define INF 1000

typedef struct node {
	int start, end;
	int len;
};

int n, m;
int sea[MAX][MAX];
int dy[4] = { -1, 1, 0, 0 }; // 위, 아래, 오른쪽, 왼쪽
int dx[4] = { 0, 0, 1, -1 };
vector<node> graph;
vector<int> parent;

// 다리길이 오름차순 정렬
struct comp {
	bool operator()(node a, node b) {
		return a.len > b.len;
	}
};

// 부모집합 찾기
int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

// 합집합
void unionSet(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	
	parent[pb] = pa;
}

// 섬 번호 표시
void bfs(int sy, int sx, int num) {
	bool visited[MAX][MAX] = { false, };
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = true;
	sea[sy][sx] = num;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (sea[ny][nx] == 1) {
				sea[ny][nx] = num;
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

int bridge(int a, int b) {
	vector<pair<int, int>> islandA, islandB;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sea[i][j] == a) islandA.push_back({ i, j });
			else if (sea[i][j] == b) islandB.push_back({ i, j });
		}
	}

	int bridgeLen = INF;
	for (int i = 0; i < islandA.size(); i++) {
		pair<int, int> src = islandA[i];
		for (int j = 0; j < islandB.size(); j++) {
			pair<int, int> dst = islandB[j];
			int len = 0;
			bool flag = true;
			if (src.first == dst.first) {
				// 다리 사이에 섬이 있으면 안됨
				if (src.second < dst.second) {
					for (int k = src.second + 1; k < dst.second; k++) {
						if (sea[src.first][k] != 0) {
							flag = false;
							break;
						}
					}
				}
				else {
					for (int k = dst.second + 1; k < src.second; k++) {
						if (sea[src.first][k] != 0) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) continue;
				len = abs(src.second - dst.second) - 1;
			}
			else if (src.second == dst.second) {
				// 다리 사이에 섬이 있으면 안됨
				if (src.first < dst.first) {
					for (int k = src.first + 1; k < dst.first; k++) {
						if (sea[k][src.second] != 0) {
							flag = false;
							break;
						}
					}
				}
				else {
					for (int k = dst.first + 1; k < src.first; k++) {
						if (sea[k][src.second] != 0) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) continue;
				len = abs(src.first - dst.first) - 1;
			}
			else continue;

			if (len > 1 && bridgeLen > len) bridgeLen = len;
		}
	}

	if (bridgeLen == INF) return -1;
	else return bridgeLen;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &sea[i][j]);
		}
	}

	// 섬 번호 표시 (2번부터)
	int num = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sea[i][j] == 1) {
				bfs(i, j, num++);
			}
		}
	}

	/* 크루스칼 */
	priority_queue<node, vector<node>, comp> pq;
	// 부모 초기화
	parent.resize(num, 0);
	for (int i = 2; i < num; i++) parent[i] = i;

	// 모든 섬 탐색
	for (int src = 2; src < num; src++) {
		for (int dst = src + 1; dst < num; dst++) {
			int len = bridge(src, dst);
			// 다리가 만들어질 수 있으면 연결
			if (len != -1) {
				graph.push_back({ src, dst, len });
				pq.push({ src, dst, len });
			}
		}
	}

	int answer = 0; // 연결된 다리 길이 총합
	int cnt = 0; // 연결된 다리 개수
	bool isConnected = false;
	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();

		// 가지치기 (간선 모두 고르면 끝)
		if (cnt == (num - 2) - 1) break;
		// 아직 연결되지 않은 경우
		if (find(cur.start) != find(cur.end)) {
			cnt++;
			unionSet(cur.start, cur.end);
			answer += cur.len;
		}
	}
	if (cnt == (num - 2) - 1) isConnected = true;
	
	// 연결된 다리가 없으면 -1
	if (answer == 0 || !isConnected) answer = -1;
	printf("%d\n", answer);
	return 0;
}
