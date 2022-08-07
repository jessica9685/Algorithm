# 연습문제 : 거스름돈.py
def solution(n, money):
    # dp[i]: i원을 만들 수 있는 경우의 수
    dp = [0 for i in range(n + 1)]
    dp[0] = 1 # 초기화
    
    for coin in money : # 각 화폐 단위에 대하여 경우의 수 세기
        for i in range(1, n + 1) :
            # i원 = (i - coin)원 만드는 경우의 수 + 기존 i원 만드는 경우의 수
            if i >= coin :
                dp[i] += dp[i - coin]
        
    return dp[n]
