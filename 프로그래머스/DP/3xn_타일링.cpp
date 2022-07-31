// 연습문제 : 3xn_타일링.cpp
#include <string>
#include <vector>
using namespace std;
#define MOD 1000000007

typedef long long ll;

int solution(int n) {
    int answer = 0;
    ll dp[5001] = { 0, };
    
    // 홀수이면 불가능 -> 경우의 수 0
    if(n % 2 == 1) answer = 0;
    else { // 짝수일 때
        dp[2] = 3;
        dp[4] = 11;
        if(n >= 6){
            // f(n) = f(n - 2) * 4 - f(n - 4)
            // 주의! moduler 연산이므로 위 식 그대로 계산하면 음수 나올 수 있음
            // moduler 연산 분배법칙 이용
            // (A - B) % MOD = ((A % MOD) - (B % MOD) + MOD) % MOD
            for(int i = 6; i <= n; i += 2){
                dp[i] = ((dp[i - 2] * 4 % MOD) - (dp[i - 4] % MOD) + MOD) % MOD;
            }
        }
        answer = dp[n];
    }
    
    return answer;
}
