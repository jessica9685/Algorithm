연습문제 : 숫자_블록.py
def solution(begin, end):
    answer = []
    
    # 각 위치의 블록 번호 = 해당 위치의 최대 약수
    for num in range(begin, end + 1):
        block = 1
        # 2 ~ 루트n까지 탐색
        for b in range(2, int(num ** 0.5) + 1):
            if num % b == 0:
                block = num // b
                # 최대 블록 번호를 넘어서면 1로 갱신 후 패스
                if block > 10000000:
                    block = 1
                    continue
                else: break
        answer.append(block)
    
    # 1번에는 아무것도 없음
    if begin == 1: 
        answer[0] = 0
    
    return answer
