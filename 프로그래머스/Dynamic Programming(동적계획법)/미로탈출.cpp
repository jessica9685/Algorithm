// 2021 카카오 채용연계형 인턴십 - 미로탈출.cpp
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1010
#define INF 987654321

// graph 구조체
typedef struct node {
	int next;
	int cost;
	bool valid; // 활성화된 경로이면 true
};

// 우선순위 큐 구조체
typedef struct qNode {
	int cur; // 현재 노드
	int state; // 함정 상태
	int cost; // 현재까지의 비용
};

// 우선순위 큐 비교함수 (cost 오름차순)
struct comp {
	bool operator()(qNode a, qNode b) {
		return a.cost > b.cost;
	}
};

/* 전역 변수 */
bool isTrap[MAX]; // i가 trap이면 true
int trapIdx[MAX]; // trap node를 bit로 저장하기 위함 (0 ~ 9번)
int dist[MAX][1 << 10]; // dist[정점][함정 활성화 상태(state)]
vector<node> graph[MAX]; // 경로 그래프

// trap의 활성화 여부 확인
bool trap_state(int next, int state) { // next : 정점, state : 현재 함정 활성화 상태
	if (!(state & (1 << trapIdx[next]))) return false;
	else return true;
}

// 함정 활성화
int active_trap(int state, int next) {
	return (state | (1 << trapIdx[next]));
}

// 함정 비활성화
int unactive_trap(int state, int next) {
	return (state ^ (1 << trapIdx[next]));
}

// 다익스트라
int dijkstra(int n, int start, int end) {
	// dist 배열 초기화 (2^10 = 1024)
	for (int i = 1; i <= n; i++) fill(dist[i], dist[i] + 1030, INF);

	priority_queue<qNode, vector<qNode>, comp> pq;
	pq.push({ start, 0, 0 }); // 현재 노드, 함정 상태, 비용
	dist[start][0] = 0;

	while (!pq.empty()) {
		int cur = pq.top().cur;
		int state = pq.top().state;
		int cost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].next;
			int nextCost = cost + graph[cur][i].cost; // 다음 정점까지의 비용
			bool edgeState = graph[cur][i].valid; // 다음 간선의 활성화 상태
			int nextState = state; // 다음 함정 상태

			// 1. 현재 함정 X, 다음 함정 X
			if (!isTrap[cur] && !isTrap[next]) {
				// 다음 정점으로 갈 수 있으면
				if (edgeState) {
					// dist 갱신
					if (dist[next][nextState] > nextCost) {
						dist[next][nextState] = nextCost;
						pq.push({ next, nextState, nextCost });
					}
				}
			}
			// 2. 현재 X, 다음 O
			else if (!isTrap[cur] && isTrap[next]) {
				if (edgeState != trap_state(next, state)) {
					// 활성 -> 비활성
					if (trap_state(next, state)) nextState = unactive_trap(nextState, next);
					// 비활성 -> 활성
					else nextState = active_trap(nextState, next);

					if (dist[next][nextState] > nextCost) {
						dist[next][nextState] = nextCost;
						pq.push({ next, nextState, nextCost });
					}
				}
			}
			// 3. 현재 O, 다음 X
			else if (isTrap[cur] && !isTrap[next]) {
				// 현재 함정 비활성화 & 다음 간선 활성화
				// 현재 함성 활성화 & 다음 간선 비활성화
				if (edgeState != trap_state(cur, state)) {
					if (dist[next][nextState] > nextCost) {
						dist[next][nextState] = nextCost;
						pq.push({ next, nextState, nextCost });
					}
				}
			}
			// 4. 현재 O, 다음 O
			else if (isTrap[cur] && isTrap[next]) {
				bool cur_trap_state = trap_state(cur, state);
				bool next_trap_state = trap_state(next, state);

				// 두개 다 활성화/비활성화 && 다음 간선 활성화
				// 둘 중 하나만 활성화 && 다음 간선 비활성화
				if (((cur_trap_state == next_trap_state) && edgeState)
					|| ((cur_trap_state != next_trap_state) && !edgeState)) {
					if (next_trap_state) nextState = unactive_trap(nextState, next);
					else nextState = active_trap(nextState, next);

					if (dist[next][nextState] > nextCost) {
						dist[next][nextState] = nextCost;
						pq.push({ next, nextState, nextCost });
					}
				}
			}
		}
	}

	// 최솟값 찾기
	int result = INF;
	for (int i = 0; i < (1 << 10); i++) {
		if(result > dist[end][i]) {
            result = dist[end][i];
        }
	}

	return result;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	int answer = 0;

	// graph 배열 초기화
	for (auto r : roads) { // 그래프로 저장
		graph[r[0]].push_back({ r[1], r[2], true });
		graph[r[1]].push_back({ r[0], r[2], false });
	}
	
	// trap 인덱스 설정
	for (int i = 0; i < traps.size(); i++) {
		int idx = traps[i];
		isTrap[idx] = true;
		trapIdx[idx] = i;
	}
    
	answer = dijkstra(n, start, end);
	return answer;
}
