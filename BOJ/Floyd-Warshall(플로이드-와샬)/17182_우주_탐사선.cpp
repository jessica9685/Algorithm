// 17182_우주_탐사선.cpp
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10
#define INF 100000

int n, start;
int ans;
int dist[MAX][MAX];
bool visited[MAX] = { false, };

void dfs(int cur, int cnt, int time) {
    if (cnt == n) {
        ans = min(ans, time);
        return;
    }

    visited[cur] = true;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        dfs(i, cnt + 1, time + dist[cur][i]);
        visited[i] = false;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &start);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // 각 행성을 가는데 걸리는 최소 시간 계산 (플로이드-와샬)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ans = INF;
    dfs(start, 1, 0);

    printf("%d\n", ans);
    return 0;
}
