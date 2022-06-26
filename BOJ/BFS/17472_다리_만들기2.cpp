// 17472_다리_만들기2.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 1000

int n, m;
int ocean[MAX][MAX];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// 각 섬 영역에 번호 표시
void numbering(int sy, int sx, int num) {
	bool visited[MAX][MAX] = { false, };
	queue<pair<int, int>> q;
	visited[sy][sx] = true;
	q.push({ sy, sx });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		ocean[y][x] = num;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (ocean[ny][nx] == 0) continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

// A와 B를 연결하는 다리 길이 구하기
int build_bridge(int a, int b) {
	vector<pair<int, int>> islandA, islandB;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ocean[i][j] == a) islandA.push_back({ i, j });
			else if (ocean[i][j] == b) islandB.push_back({ i, j });
		}
	}

	int bridge_len = INF;
	for (auto src : islandA) {
		for (auto dst : islandB) {
			int len = 0;
			bool seaFlag = true; // 현재 위치가 바다이면 true
			
			// 가로 다리
			if (src.first == dst.first) {
				// 다리 사이에 섬 있으면 패스
				if (src.second < dst.second) {
					for (int i = src.second + 1; i < dst.second; i++) {
						if (ocean[src.first][i] != 0) {
							seaFlag = false;
							break;
						}
					}
				}
				else {
					for (int i = dst.second + 1; i < src.second; i++) {
						if (ocean[src.first][i] != 0) {
							seaFlag = false;
							break;
						}
					}
				}

				if (!seaFlag) continue;
				len = abs(src.second - dst.second) - 1;
			}
			
			// 세로 다리
			else if (src.second == dst.second) {
				// 다리 사이에 섬 있으면 패스
				if (src.first < dst.first) {
					for (int i = src.first + 1; i < dst.first; i++) {
						if (ocean[i][src.second] != 0) {
							seaFlag = false;
							break;
						}
					}
				}
				else {
					for (int i = dst.first + 1; i < src.first; i++) {
						if (ocean[i][src.second] != 0) {
							seaFlag = false;
							break;
						}
					}
				}

				if (!seaFlag) continue;
				len = abs(src.first - dst.first) - 1;
			}

			// 최솟값 갱신
			if (len > 1 && bridge_len > len) bridge_len = len;
		}
	}

	if (bridge_len == INF) return -1;
	else return bridge_len;
}

/* 크루스칼 (최소 스패닝 트리) */
// 크루스칼에 사용할 구조체
typedef struct Node {
	int start, end; // 섬 2개
	int len; // 섬 사이의 다리 길이
};

// 다리길이 오름차순 정렬
struct comp {
	bool operator()(Node a, Node b) {
		return a.len > b.len;
	}
};

vector<int> parent;

// 1. 부모 찾기
int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

// 2. 합집합
void unionSet(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	parent[pb] = pa;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &ocean[i][j]);
		}
	}

	// 섬 번호 매기기 (2번부터)
	int num = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ocean[i][j] == 1) numbering(i, j, num++);
		}
	}

	/* 크루스칼 */
	priority_queue<Node, vector<Node>, comp> pq;
	
	// 부모 초기화
	parent.resize(num, 0);
	for (int i = 2; i < num; i++) parent[i] = i;

	// 모든 섬 탐색
	for (int src = 2; src < num; src++) {
		for (int dst = src + 1; dst < num; dst++) {
			int len = build_bridge(src, dst);
			// 다리가 만들어질 수 있으면 연결
			if (len != -1) pq.push({ src, dst, len });
		}
	}

	int answer = 0; // 연결된 다리 길이 총합
	int cnt = 0; // 연결된 다리 개수
	bool isConnected = false;
	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();

		// 도중에 간선 다 고르면 종료
		if (cnt == num - 2 - 1) break;
		// 아직 연결 안됐으면 연결
		if (find(cur.start) != find(cur.end)) {
			unionSet(cur.start, cur.end);
			cnt++;
			answer += cur.len;
		}
	}
	if (cnt == num - 2 - 1) isConnected = true;

	if (answer == 0 || !isConnected) answer = -1;
	printf("%d\n", answer);
	return 0;
}
