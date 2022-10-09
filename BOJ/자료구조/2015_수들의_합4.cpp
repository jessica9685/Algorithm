// 2015_수들의_합4.cpp
#include <bits/stdc++.h>
using namespace std;

int n, k;
int sum[200001] = {0, }; // seq[n]: A[1] ~ A[n]까지의 누적합
// cnt_map[k]: 부분합이 k가 되는 경우의 수
// 최대 경우의 수 = n(n + 1) / 2 => 약 20,000,100,000 (long long)
map<int, long long> cnt_map; 

int main(){
    scanf("%d %d", &n, &k);

    // 누적합 저장
    for(int i = 1; i <= n; i++){
        int value;
        scanf("%d", &value);
        sum[i] = sum[i - 1] + value;
    }

    long long answer = 0;
    for(int i = 1; i <= n; i++){
        // 누적합이 k이면 경우의 수 +1
        if(sum[i] == k) answer++;

        // k = sum[i] - sum[j]
        // sum[j] = sum[i] - k
        answer += cnt_map[sum[i] - k];
        
        // sum[i]에 대한 경우의 수 추가
        cnt_map[sum[i]]++;
    }

    printf("%lld\n", answer);
    return 0;
}
