// 연습문제 : 야근_지수.cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    // 우선순위 큐에 넣기
    priority_queue<int> pq;
    for(auto w : works) pq.push(w);
    
    // 매번 최대값을 찾아 -1 해줌
    // 우선순위 큐 사용
    // sort를 사용해 최대값을 찾으면 효율성에서 틀림
    while(n > 0){
        int maxi = pq.top();
        pq.pop();
        
        // 최대값이 0이면 종료
        if(maxi == 0) break;
        
        pq.push(maxi - 1);
        n--;
    }
    
    // 야근 피로도 계산
    long long answer = 0;
    while(!pq.empty()){
        int num = pq.top();
        pq.pop();
        
        answer += (num * num);
    }    
    return answer;
}
