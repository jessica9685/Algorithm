// 2021_카카오 : 합승_택시_요금.cpp
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 20000001

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	for (auto& p : fares) {
		int start = p[0];
		int end = p[1];
		int cost = p[2];
		dist[start][end] = cost;
		dist[end][start] = cost;
	}

	// 플로이드-와샬
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int z = 1; z <= n; z++) {
				dist[y][z] = min(dist[y][z], dist[y][x] + dist[x][z]);
			}
		}
	}

	int answer = dist[s][a] + dist[s][b];
	for (int i = 1; i <= n; i++) {
		if(s != i){
            int route = dist[s][i] + dist[i][a] + dist[i][b];
		    answer = min(answer, route);
        }
	}

	return answer;
}
