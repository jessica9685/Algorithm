// 경유지가_있는_경로.cpp
#include <iostream>
using namespace std;
#define MAX 16

int n, m, k;
int dp[MAX][MAX];

int find_path(int sy, int sx, int ey, int ex){
    for(int y = sy + 1; y <= ey; y++){
        for(int x = sx + 1; x <= ex; x++){
            dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
        }
    }
    return dp[ey][ex];
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) dp[i][j] = 1;
    }

    int answer = 0;
    if(k == 0) answer = find_path(1, 1, n, m);
    else{
        int y = k / m;
        int x = k % m;
        if(x == 0) x = m;
        else y += 1;

        answer = find_path(1, 1, y, x) * find_path(y, x, n, m);
    }

    printf("%d\n", answer);
    return 0;
}
