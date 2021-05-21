// 프로그래머스 : Greedy(탐욕법) - 큰_수_만들기.cpp
#include <string>
#include <vector>
using namespace std;

// 주어진 숫자의 순서는 지켜야 함.
string solution(string number, int k) {
    string answer = "";
    
    int s = number.size() - k;    
    int start = 0;
    
    for(int i = 0; i < s; i++){
        char maxNum = number[start];
        int maxIdx = start;
        
        // 범위 내에서 가장 큰 수 구하기
        for(int j = start; j <= i + k; j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += maxNum;
    }
    
    return answer;
}
