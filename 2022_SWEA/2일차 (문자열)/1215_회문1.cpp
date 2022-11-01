// 1215_회문1.cpp
#include <iostream>
#include <string>
using namespace std;

char board[8][8];
int dy[2] = {0, 1};
int dx[2] = {1, 0};

bool palindrome(int y, int x, int n, int d){
    int ny = y + dy[d] * (n - 1);
    int nx = x + dx[d] * (n - 1);

    if(ny < 0 || nx < 0 || ny >= 8 || nx >= 8) return false;
    for(int i = 0; i <= (n >> 1); i++){
        ny = y + dy[d] * (n - 1 - i);
        nx = x + dx[d] * (n - 1 - i);                                                                      
 
        if(board[y + i * dy[d]][x + i * dx[d]] != board[ny][nx]) return false;  
    }
    return true;                                                                        
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T = 10;
    for(int tc = 1; tc <= T; tc++){
        int n; // 회문 길이
        cin >> n;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++) {
                cin >> board[i][j];
            }
        }

        int answer = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                for(int d = 0; d < 2; d++){
                    if(palindrome(i, j, n, d)) answer++;
                }
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
