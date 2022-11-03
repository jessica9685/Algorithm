// 10966_물놀이를_가자.cpp
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1000
#define INF 2000000

int n, m;
char board[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int dist[MAX][MAX];

int bfs(vector<pair<int, int>> start){
    queue<pair<int, int>> q;
    for(auto s : start) {
        q.push(s);
        dist[s.first][s.second] = 0;
    }
 
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(board[ny][nx] == 'W') continue;
            if(dist[ny][nx] > dist[y][x] + 1){
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    // 총합 구하기
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'L') answer += dist[i][j];
        }
    }
    return answer;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> n >> m;
        vector<pair<int, int>> start;
        for(int i = 0; i < n; i++){
            string str;
            cin >> str;
            for(int j = 0; j < m; j++){
                board[i][j] = str[j];
                dist[i][j] = INF; // 초기화
                // 물을 시작점으로
                if(board[i][j] == 'W') start.push_back({i, j});
            }
        }

        int answer = bfs(start);
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
