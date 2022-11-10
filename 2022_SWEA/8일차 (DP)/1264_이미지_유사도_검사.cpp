// 1264_이미지_유사도_검사.cpp
// LCS
#include <iostream>
using namespace std;
#define MAX 501

int n;
string x, y;

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> n;
        cin >> x >> y;
        
        int dp[MAX][MAX]; // x[1] ~ x[i]와 y[1] ~ y[j]를 비교했을 때 LCS 길이
        for(int i = 0; i <= n; i++){ // 초기화
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        double answer = (double)dp[n][n] / n * 100;
        printf("#%d %.2f\n", tc, answer);
    }
    return 0;
}
