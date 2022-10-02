// 7579_앱.cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
int app[101]; // A1 ~ An이 사용 중인 메모리 바이트 수
int cost[101]; // 각 앱을 비활성화했을 때의 비용
// 각 메모리 크기가 최대 10,000,000 -> 공간메모리 초과
// 앱 개수 100 * 각 앱의 최대 비용 100
// dp[앱 번호][앱 비활성화 비용] = 확보 가능한 최대 메모리 크기
int dp[101][10001]; 

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &app[i]);

    int costSum = 0; // 모든 앱을 비활성화했을 때의 비용
    for(int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
        costSum += cost[i];
    }

    for(int i = 1; i <= n; i++){ // 각 앱에 대하여
        for(int c = 0; c <= costSum; c++){ // 비용 및 크기 계산
            if(c - cost[i] >= 0){ // 갱신 가능하면 갱신
                dp[i][c] = max(dp[i][c], dp[i - 1][c - cost[i]] + app[i]);
            }
            // 최대 메모리 크기 갱신
            dp[i][c] = max(dp[i][c], dp[i - 1][c]);
        }
    }

    // 최소 비용 찾기
    for(int c = 0; c <= costSum; c++){
        if(dp[n][c] >= m){
            printf("%d\n", c);
            break;
        }
    }
    return 0;
}
