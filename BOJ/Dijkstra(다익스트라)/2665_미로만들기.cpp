// 2665_미로만들기.cpp
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 51
#define INF 10000

int n;
int rooms[MAX][MAX];
/* 같은 곳을 여러 번 방문해도 ok */
int visited[MAX][MAX]; // 검은방 -> 흰방 최소 변경 횟수
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs() {
    memset(visited, INF, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 0;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(rooms[ny][nx] == 1) { // white
                if(visited[ny][nx] > visited[y][x]) {
                    visited[ny][nx] = visited[y][x];
                    q.push({ny, nx});
                }
            }
            else { // black
                if(visited[ny][nx] > visited[y][x] + 1) {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &rooms[i][j]);
        }
    }

    bfs();
    int answer = visited[n - 1][n - 1];

    printf("%d\n", answer);
    return 0;
}
