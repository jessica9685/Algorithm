// 1260_화학물질2.cpp
#include <iostream>
#include <deque>
#include <queue>
using namespace std;
#define MAX 101
#define INF 999999999

typedef struct Matrix{
    int r, c;
} Matrix;

int n;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

deque<Matrix> matrix, order;
int dp[21][21]; // 행렬 i부터 j까지의 최소 곱셈 횟수

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

void search_matrix(int sy, int sx){
    queue<pair<int, int>> q;
    q.push({sy, sx}); 
    visited[sy][sx] = true;

    int ey = sy, ex = sx;
    while(!q.empty()){
        ey = q.front().first;
        ex = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++){
            int ny = ey + dy[d];
            int nx = ex + dx[d];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx] || board[ny][nx] == 0) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    matrix.push_back({ey - sy + 1, ex - sx + 1});
}

int mcm(int start, int end){
    // 자기 자신이면 0
    if(start == end) return 0;

    // 이미 갱신된 값이면 리턴
    if(dp[start][end] != INF) return dp[start][end];

    for(int i = start; i < end; i++){
        int left = mcm(start, i);
        int right = mcm(i + 1, end);

        dp[start][end] = min(dp[start][end],
                        left + right + order[start].r * order[i].c * order[end].c);
    }

    return dp[start][end];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        // 초기화 & input
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
                visited[i][j] = false;
            }
        }
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++) dp[i][j] = INF;
        }
        matrix.clear();
        order.clear();

        // 행렬 찾기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] || board[i][j] == 0) continue;
                search_matrix(i, j);
            }
        }

        // 행렬 곱셈이 가능한 순서대로 정렬       
        order.push_back(matrix[0]);
        matrix.pop_front();
        while(!matrix.empty()){
            for(int i = 0; i < matrix.size(); i++){
                if(order.back().c == matrix[i].r){
                    order.push_back(matrix[i]);
                    matrix.erase(matrix.begin() + i);
                    break;
                }
                else if(order.front().r == matrix[i].c){
                    order.push_front(matrix[i]);
                    matrix.erase(matrix.begin() + i);
                    break;
                }
            }
        }

        int cnt = order.size();
        int answer = mcm(0, cnt - 1);
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
