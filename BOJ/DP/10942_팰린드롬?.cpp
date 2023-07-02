// 10942_팰린드롬?.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2001

int n, m;
int seq[MAX];
bool dp[MAX][MAX]; // dp[i][j] : i ~ j 구간까지 팰린드롬이면 true

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &seq[i]);
        dp[i][i] = true; // 1칸 팰린드롬
    }

    for(int i = 1; i < n; i++){
        if(seq[i] == seq[i + 1]){
            dp[i][i + 1] = true;
        }
    }

    for(int k = 2; k <= n - 1; k++){ // 칸 수
        for(int i = 1; i <= n - k; i++){
            int j = i + k;

            // i (i + 1) ... (j - 1) j
            // i == j이고 (i + 1) ~ (j + 1)이 팰린드롬이면 i ~ j도 팰린드롬
            if(seq[i] == seq[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    scanf("%d", &m);
    while(m--){
        int s, e;
        scanf("%d %d", &s, &e);

        if(dp[s][e]) printf("1\n");
        else printf("0\n");
    }

    return 0;
}
