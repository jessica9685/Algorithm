// 18428_감시_피하기.cpp
#include <iostream>
#include <vector>
using namespace std;
#define MAX 6

int n;
char board[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> obstacle, teacher;

// 선생님이 학생을 볼 수 없으면 true
bool check(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y;
        int nx = x;

        while(ny >= 0 && nx >= 0 && ny < n && nx < n){
            // 장애물이면 break
            if(board[ny][nx] == 'O') break;

            // 학생을 만나면 fasle
            if(board[ny][nx] == 'S') return false;

            ny += dy[i];
            nx += dx[i];
        }
    }

    return true;
}

void dfs(int cnt, int idx){
    if(cnt == 3){
        // 선생님이 학생을 찾을 수 있으면 종료
        for(auto t : teacher){
            if(!check(t.first, t.second)) return;
        }

        // 학생이 모두 가려지는 경우
        printf("YES\n");
        exit(0);
    }

    for(int i = idx; i < obstacle.size(); i++){
        int y = obstacle[i].first;
        int x = obstacle[i].second;

        board[y][x] = 'O';
        dfs(cnt + 1, i + 1);
        board[y][x] = 'X';
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &board[i][j]);

            if(board[i][j] == 'X') obstacle.push_back({i, j});
            else if(board[i][j] == 'T') teacher.push_back({i, j});
        }
    }

    dfs(0, 0);
    printf("NO\n");
    return 0;
}
