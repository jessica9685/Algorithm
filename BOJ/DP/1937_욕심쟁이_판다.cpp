// 1937_욕심쟁이_판다.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int n;
int forest[MAX][MAX];
int dp[MAX][MAX]; // dp[i][j]: i행 j열에서 시작했을 때 갈 수 있는 최대 칸 수
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int dfs(int y, int x){
    // 이미 값이 존재하면 종료
    if(dp[y][x] != 0) return dp[y][x];
    dp[y][x] = 1; // 초기값 == 1

    for(int d = 0; d < 4; d++){
        int ny = y + dy[d];
        int nx = x  + dx[d];

        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(forest[y][x] < forest[ny][nx]){
            dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
        }
    }

    return dp[y][x];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &forest[i][j]);
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answer = max(answer, dfs(i, j));
        }
    }
    printf("%d\n", answer);
    return 0;
}
