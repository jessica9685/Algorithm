// 14002_가장_긴_증가하는_부분_수열4.cpp
#include <bits/stdc++.h>
using namespace std;

int n; // 수열 크기
int seq[1001]; // 수열
int dp[1001]; // 가장 긴 증가하는 부분 수열의 길이
int lis[1001]; // LIS를 이루는 원소들의 index 저장

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &seq[i]);
    }

    int max_len = 0; // 가장 긴 증가하는 부분 수열의 길이
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(seq[j] < seq[i]){
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    lis[i] = dp[i];
                }
            }
        }
        max_len = max(max_len, dp[i]);
    }

    // 길이 출력
    printf("%d\n", max_len); 
    // LIS 출력
    stack<int> lis_seq;
    for(int i = n; i > 0; i--){
        if(max_len == 0) break;
        if(lis[i] == max_len){
            lis_seq.push(seq[i]);
            max_len--;
        }
    }
    while(!lis_seq.empty()){
        printf("%d ", lis_seq.top());
        lis_seq.pop();
    }
    printf("\n");
    return 0;
}
