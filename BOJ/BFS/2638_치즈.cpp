// 2638_치즈.cpp
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 100

int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

// 주변 공기 체크 (바깥 영역)
void bfs(int sy, int sx) {
    memset(visited, false, sizeof(visited));

    visited[sy][sx] = true;
    queue<pair<int, int>> q;
    q.push({sy, sx});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            // 이미 방문했거나 치즈인 경우 패스
            if(visited[ny][nx] || board[ny][nx] == 1) continue;

            visited[ny][nx] = true;
            board[ny][nx] = 2;
            q.push({ny, nx});
        }
    }
}

bool is_melt(int y, int x) {
    int air = 0;

    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (board[ny][nx] == 2) air++;
    }

    if (air >= 2) return true;
    else return false;
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    int time = 0;
    while (true) {
        // 주변 공기 체크
        bfs(0, 0);

        queue<pair<int, int>> q; // 녹는 치즈 위치
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && is_melt(i, j)) {
                    q.push({i, j});
                }
            }
        }

        // 치즈 녹이기
        if (!q.empty()) {
            time++;
            while (!q.empty()) {
                board[q.front().first][q.front().second] = 0;
                q.pop();
            }
        }
        else break;
    }

    printf("%d\n", time);
    return 0;
}
