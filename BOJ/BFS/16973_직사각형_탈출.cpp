// 16973_직사각형_탈출.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

struct State{
    int y, x;
    int cnt;
};

int n, m, h, w;
int board[MAX][MAX];
int dy[4] = {-1, 1, 0, 0}; // up, down, left, right
int dx[4] = {0, 0, -1, 1};

// 이동 가능한 위치이면 true
bool canMove(int y, int x, int d){
    if(d == 0){ // up
        for(int i = x; i < x + w; i++){
            if(board[y][i] == 1) return false;
        }
    }
    else if(d == 1){ // down
        int ny = y + h - 1;
        if(ny > n) return false;

        for(int i = x; i < x + w; i++){
            if(board[ny][i] == 1) return false;
        }
    }
    else if(d == 2){ // left
        for(int i = y; i < y + h; i++){
            if(board[i][x] == 1) return false;
        }
    }
    else{ // right
        int nx = x + w - 1;
        if(nx > m) return false;

        for(int i = y; i < y + h; i++){
            if(board[i][nx] == 1) return false;
        }
    }
    return true;
}

int bfs(int sy, int sx, int fy, int fx){
    queue<State> q;
    bool visited[MAX][MAX] = {false, };
    visited[sy][sx] = true;
    q.push({sy, sx, 0});

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if(y == fy && x == fx) return cnt;

        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(ny < 1 || nx < 1 || ny > n || nx > m) continue;
            if(visited[ny][nx] || board[ny][nx] == 1) continue;
            if(canMove(ny, nx, d)){ // 이동 가능하면
                visited[ny][nx] = true;
                q.push({ny, nx, cnt + 1});
            }
        }
    }

    return -1;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &board[i][j]);
        }
    }

    int sy, sx, fy, fx;
    scanf("%d %d %d %d %d %d", &h, &w, &sy, &sx, &fy, &fx);

    int ans = bfs(sy, sx, fy, fx);
    printf("%d\n", ans);
    return 0;
}
