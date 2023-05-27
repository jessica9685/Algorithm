// 6087_레이저_통신.cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
#define INF 100000

int w, h;
char board[MAX][MAX];
vector<pair<int, int>> endpoint; // C 2칸 위치
int dist[MAX][MAX];
bool visited[MAX][MAX][4] = {false, }; // 중복 방문 체크
int dy[4] = {-1, 0, 1, 0}; // up, right, down, left
int dx[4] = {0, 1, 0, -1};

struct PQ{
    int y, x; // 현재 위치
    int dir; // 현재 방향
    int cnt; // 거울 개수
};

struct comp{ // 거울 개수 오름차순 정렬
    bool operator()(PQ a, PQ b) {
        return a.cnt > b.cnt;
    }
};

void bfs() {
    int sy = endpoint[0].first;
    int sx = endpoint[0].second;
    
    /* init */
    dist[sy][sx] = 0;
    priority_queue<PQ, vector<PQ>, comp> pq;
    for(int d = 0; d < 4; d++) {
        pq.push({sy, sx, d, 0});
    }

    while(!pq.empty()) {
        int y = pq.top().y;
        int x = pq.top().x;
        int dir = pq.top().dir;
        int cnt = pq.top().cnt;
        pq.pop();

        visited[y][x][dir] = true;

        if(dist[y][x] < cnt) continue;
        // 도착점에 도달하면 패스
        if(y == endpoint[1].first && x == endpoint[1].second) continue;

        for(int i = 0; i < 4; i++) {
            // 반대 방향은 이동 불가
            if(i == (dir + 2) % 4) continue;

            int ny = y + dy[i];
            int nx = x + dx[i];
            int ndir = i;
            int ncnt = cnt; // 거울 X
            if(ndir != dir) ncnt = cnt + 1; // 거울 O

            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(board[ny][nx] == '*') continue;
            if(visited[ny][nx][ndir]) continue;

            // 거울을 놓는 방향이 다를 수 있기 때문에 ncnt가 같은 경우도 고려
            if(dist[ny][nx] >= ncnt) {
                dist[ny][nx] = ncnt;
                pq.push({ny, nx, ndir, ncnt});
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    
    scanf("%d %d", &w, &h);

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'C') {
                endpoint.push_back({i, j});
            }
            dist[i][j] = INF;
        }
    }

    bfs();
    
    int answer = dist[endpoint[1].first][endpoint[1].second];
    printf("%d\n", answer);
    return 0;
}
