// 프로그래머스 : 스택/큐 - 프린터.cpp
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // first: 문서번호, second: 중요도
    // 대기 큐
    queue<pair<int, int>> q;
    // 중요도 우선순위 큐
    priority_queue<int> pq; 
    
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    int cnt = 0;
    while(!q.empty()){
        int idx = q.front().first;
        int pri = q.front().second;
        q.pop();
        
        // 현재 문서가 우선순위 1순위이면
        if(pq.top() == pri){
            pq.pop();
            cnt++;
            
            if(idx == location){
                answer = cnt;
                break;
            }
        }
        else{ // 우선순위 1순위와 현재 문서가 다르면
            q.push({idx, pri});
        }
    }
    
    return answer;
}
