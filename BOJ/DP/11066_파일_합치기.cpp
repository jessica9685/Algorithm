// 11066_파일_합치기.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500 + 1
#define INF 987654321

int T;
int n;

int files[MAX];
int dp[MAX][MAX]; // dp[a][b] : a ~ b 구간의 최소비용
int sum[MAX]; // sum[a] : 1 ~ a까지의 합

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &T);

    while(T--){
        scanf("%d", &n);

        for(int i = 1; i <= n; i++){
            scanf("%d", &files[i]);
            sum[i] = sum[i - 1] + files[i];
        }

        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= n- j; i++){
                dp[i][i + j] = INF;

		/*
			dp[4][11]의 최소값
			= dp[4][5] + dp[6][11] + (sum[11] - sum[3])
			= dp[i][k] + dp[k + 1][i + j] + (sum[i + j] - sum[i - 1])
		*/
                for(int k = i; k < i + j; k++){
                    dp[i][i + j] = min(dp[i][i + j], 
                                    dp[i][k] + dp[k + 1][i + j] + sum[i + j] - sum[i - 1]);
                }
            }
        }
        
        printf("%d\n", dp[1][n]);
    }

    return 0;
}
