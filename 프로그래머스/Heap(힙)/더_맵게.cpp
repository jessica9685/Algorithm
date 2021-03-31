// 프로그래머스 : 힙(Heap) - 더_맵게.cpp
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 오름차순 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq;
    //int cnt = scoville.size(); // 총 음식 개수
    for(auto s : scoville) pq.push(s);
    
    while(pq.size() > 1){
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        
        int mixture = s1 + (s2 * 2);
        pq.push(mixture);
        answer++;
        
        if(pq.top() >= K) break;
    }
    
    if(pq.top() < K) answer = -1;
    
    return answer;
}
