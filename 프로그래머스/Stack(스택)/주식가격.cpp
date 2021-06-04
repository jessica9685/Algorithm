// 프로그래머스 : 스택/큐 - 주식가격.cpp
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    
    stack<int> s; // index stack (가격이 오르면 push)
    
    for(int i = 0; i < size; i++){
        // 스택이 비어있지 않고
        // 스택의 top 가격이 현재 가격보다 클 경우 (가격이 떨어졌을 때)
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        // 가격이 오르고 있으면 push
        s.push(i);
    }
    
    // 스택에 값이 남아있을 때
    while(!s.empty()){
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }
    
    return answer;
}
