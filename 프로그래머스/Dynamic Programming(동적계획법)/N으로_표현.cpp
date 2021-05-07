// 프로그래머스 : 동적계획법 - N으로_표현.cpp
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {   
    int answer = -1;
    // 크기 = 8
    vector<set<int>> cases(8);
    
    int num = 0;
    // N을 i번 사용한 경우의 수
    for(int i = 0; i < 8; i++){
        // N으로 이루어진 수 넣기(5, 55, 555...)
        num = num * 10 + N;
        cases[i].insert(num);
        
        for(int j = 0; j < i; j++){
            for(auto &a : cases[j]){
                for(auto &b : cases[i - j - 1]){
                    cases[i].insert(a * b);
                    cases[i].insert(a + b);
                    cases[i].insert(a - b);
                    if(b != 0) cases[i].insert(a / b);
                }
            }
        }
        
        // number를 만들 수 있으면
        if(cases[i].find(number) != cases[i].end()){
            answer = i + 1;
            break;
        }
    }
    
    // 8회 이하로 경우의 수가 없으면 -1
    return answer;
}
