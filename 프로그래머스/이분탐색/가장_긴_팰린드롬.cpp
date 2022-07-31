// 연습문제 : 가장_긴_팰린드롬.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 팰린드롬의 길이 리턴
int is_palindrome(string str, int left, int right){
    // 기준점을 중심으로 좌우 이분탐색
    while(left >= 0 && right < str.size()){
        if(str[left] != str[right]) break;
        left--;
        right++;
    }
    return right - left - 1;
}

int solution(string s) {
    int answer = 0;
    
    // 각 문자를 기준점으로 
    for(int i = 0; i < s.size(); i++){
        // 짝수/홀수 길이의 팰린드롬 찾기
        int odd = is_palindrome(s, i, i);
        int even = is_palindrome(s, i - 1, i);
        
        // 최대값 갱신
        answer = max(answer, max(odd, even));
    }
    
    return answer;
}
