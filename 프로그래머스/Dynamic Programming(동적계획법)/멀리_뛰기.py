# 연습문제 : 멀리_뛰기.py
# 피보나치 수열
def solution(n):
    dp = [0 for i in range(n + 1)]
    dp[1] = 1
    if(n == 1): # test case 1
        return 1
    
    dp[2] = 2
    for i in range(3, n + 1):
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567
        
    return dp[n]
