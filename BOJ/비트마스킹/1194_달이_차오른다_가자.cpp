// 1194_달이_차오른다_가자.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 51
#define INF 1000000

int n, m;
char maze[MAX][MAX];
bool visited[MAX][MAX][1 << 6];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

struct State{
    int y, x;
    int key; // 키 보유 여부 (000000 ~ 111111)
    int cnt; // 이동 횟수
};

int bfs(pair<int, int> src){
    queue<State> q;
    q.push({src.first, src.second, 0, 0});
    visited[src.first][src.second][0] = true;

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int key = q.front().key;
        int cnt = q.front().cnt;
        q.pop();

        // 출구에 도착하면 종료
        if(maze[y][x] == '1') return cnt;

        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];

            // 범위를 벗어나면 패스
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            // 벽이거나 이미 방문했으면 패스
            if(maze[ny][nx] == '#' || visited[ny][nx][key]) continue;
            
            // 열쇠일 때
            if(maze[ny][nx] >= 'a' && maze[ny][nx] <= 'f'){
                int newKey = key | (1 << (int(maze[ny][nx] - 'a')));
                visited[ny][nx][newKey] = true;
                q.push({ny, nx, newKey, cnt + 1});
            }

            // 문일 때
            else if(maze[ny][nx] >= 'A' && maze[ny][nx] <= 'F'){
                // key가 존재하면
                if((key & (1 << int(maze[ny][nx] - 'A'))) != 0){
                    visited[ny][nx][key] = true;
                    q.push({ny, nx, key, cnt + 1});

                }
            }
            
            // 빈칸이거나 도착점일 때
            else{
                visited[ny][nx][key] = true;
                q.push({ny, nx, key, cnt + 1});
            }
        }
    }

    return -1; // 미로를 탈출할 수 없으면 -1
}

int main(){
    scanf("%d %d", &n, &m);

    pair<int, int> src;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &maze[i][j]);
            if(maze[i][j] == '0') { // 시작점 저장
                src = {i, j};
                maze[i][j] = '.';
            }
        }
    }

    int result = bfs(src);
    printf("%d\n", result);
    return 0;
}
