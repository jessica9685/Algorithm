# 연습문제 : 다음_큰_숫자.py
def solution(n):
    # n을 2진수로 변환 후 1의 개수 count
    cnt = bin(n).count('1')
    
    answer = 0
    # n+1부터 1,000,000까지의 수 중 1의 개수가 같은 것 탐색
    for num in range(n + 1, 1000001):
        next_cnt = bin(num).count('1')
        
        # 1의 개수가 같으면 리턴
        if next_cnt == cnt:
            answer = num
            break
    
    return answer
