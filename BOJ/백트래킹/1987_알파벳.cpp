// 1987_알파벳.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 20

int r, c;
char board[MAX][MAX];
bool alphabet[26];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int ans;

void dfs(int y, int x, int cnt){
    if(ans < cnt) ans = cnt;

    for(int d = 0; d < 4; d++){
        int ny = y + dy[d];
        int nx = x + dx[d];

        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(alphabet[board[ny][nx] - 'A']) continue;

        alphabet[board[ny][nx] - 'A'] = true;
        dfs(ny, nx, cnt + 1);
        // backtracking
        alphabet[board[ny][nx] - 'A'] = false;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %c", &board[i][j]);
        }
    }
    
    ans = 0;
    for(int i = 0; i < 26; i++) alphabet[i] = false;
    alphabet[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    printf("%d\n", ans);
    return 0;
}
