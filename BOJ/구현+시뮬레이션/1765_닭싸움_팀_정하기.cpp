// 1765_닭싸움_팀_정하기.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAj 40

int n, m, k;
int r, c;

int board[MAj][MAj];
int sticker[10][10];

// 스티커 회전하기
void rotate(){
    int tmp[10][10];

    memcpy(tmp, sticker, sizeof(sticker));

    // 행과 열 뒤집힘 (시계방향 90도 회전)
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            sticker[i][j] = tmp[r - 1 - j][i];
        }
    }

    swap(r, c);
}

// 붙일 수 있으면 true
bool attach(int y, int x){
    // 붙일 수 없으면 false
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sticker[i][j] == 1 && board[y + i][x + j] == 1){
                return false;
            }
        }
    }

    // 붙일 수 있으면 붙이고 true
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sticker[i][j] == 1) board[y + i][x + j] = 1;
        }
    }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);

    for(int l = 0; l < k; l++){
        scanf("%d %d", &r, &c);

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                scanf("%d", &sticker[i][j]);
            }
        }

        for(int d = 0; d < 4; d++){
            bool flag = false;
            
            for(int i = 0; i <= n - r; i++){
                if(flag) break;
                for(int j = 0; j <= m - c; j++){
                    if(attach(i, j)){
                        flag = true;
                        break;
                    }
                }
            }

            if(flag) break;
            else rotate(); // 붙일 수 없으면 회전
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1) ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
