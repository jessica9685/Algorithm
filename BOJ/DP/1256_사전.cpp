// 1256_사전.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000

int N, M, K;
// 문자열 조합의 수
// N + M <= 200
int dp[201][201]; 
string answer;

// nCr
int combination(int n, int r){
    if(n == r || r == 0) return 1;
    else if(dp[n][r] != 0) return dp[n][r];
    else{
        // nCr = n-1Cr-1 + n-1Cr
        dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
        // K의 최댓값을 벗어나면 MAX로 수정
        if(dp[n][r] > MAX) dp[n][r] = MAX;
        return dp[n][r];
    }
}

void dfs(int n, int m, int k, string str){
    // a, z 모두 다 쓴 경우 종료
    if(n + m == 0){
        answer = str;
        return;
    }

    // 1. a를 다 쓴 경우
    if(n == 0) dfs(n, m - 1, k, str + 'z');
    
    // 2. z를 다 쓴 경우
    else if(m == 0) dfs(n - 1, m, k, str + 'a');

    // 3. a, z 둘 다 남아있는 경우
    else{
        // a: (n - 1)개, z: m개일 때 문자열 개수
        int cnt = combination(n + m - 1, m);
        // k보다 크면 -> 더 앞에 존재 -> a 추가
        if(k <= cnt) dfs(n - 1, m, k, str + 'a');
        // K보다 작으면 -> 더 뒤에 존재 -> z 추가
        else dfs(n, m - 1, k - cnt, str + 'z');
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    // 문자열의 개수가 K보다 작으면 -1
    if(K > combination(N + M, N)) printf("-1\n");
    else{
        dfs(N, M, K, "");
        cout << answer << "\n";
    }
    return 0;
}
