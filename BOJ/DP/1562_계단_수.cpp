// 1562_계단_수.cpp
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000

int n;
long long dp[101][10][1 << 10]; // dp[자릿수][현재 자릿수의 숫자][사용한 숫자 체크]

int main(){
    scanf("%d", &n);
    
    // 9자리 이하이면 0~9까지의 모든 숫자가 나올 수 없음
    if(n < 10){
        printf("0\n");
        return 0;
    }

    // 1자리 수 개수 = 1 (0 제외)
    for(int j = 1; j <= 9; j++) dp[1][j][1 << j] = 1;

    for(int i = 2; i <= n; i++){ // 각 자릿수에 대해
        for(int j = 0; j < 10; j++){ // 0 ~ 9까지
            // 0000000000 ~ 1111111111 탐색
            for(int bit = 0; bit < (1 << 10); bit++){
                if(j == 0){ // 현재 숫자가 0이면 다음에는 1밖에 못옴
                    dp[i][0][bit | (1 << j)] += (dp[i - 1][1][bit] % MOD);
                }
                else if(j == 9){ // 현재 숫자가 9면 다음에는 8밖에 못옴
                     dp[i][9][bit | (1 << j)] += (dp[i - 1][8][bit] % MOD);
                }
                else{
                    dp[i][j][bit | (1 << j)] += ((dp[i - 1][j - 1][bit] + dp[i - 1][j + 1][bit]) % MOD);
                }
            }
        }
    }

    long long answer = 0;
    for(int j = 0; j <= 9; j++){
        answer = (answer + dp[n][j][(1 << 10) - 1]) % MOD;
    }
    printf("%lld\n", answer);
    return 0;
}
