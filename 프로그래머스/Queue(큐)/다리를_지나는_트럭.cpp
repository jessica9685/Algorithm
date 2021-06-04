// 프로그래머스 - 스택/큐 : 다리를_지나는_트럭.cpp
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0; // 걸린 시간
    int sum = 0; // 다리 위에 있는 트럭 무게 합
    int idx = 0; // 트럭 순서
    
    // 다리 위에 있는 트럭이 삽입된 큐
    queue<int> q; 
    
    while(1){
        time++;
        
        // 다리에 올라간 트럭 수가 최대인 경우
        if(q.size() == bridge_length){
            // 맨 앞 트럭 제거
            sum -= q.front();
            q.pop();
        }
        
        // 현재 트럭 무게 + 다음 트럭 무게 <= 다리 무게
        if(sum + truck_weights[idx] <= weight){
            // 마지막 트럭일 경우
            if(idx == truck_weights.size() - 1){
                // 마지막 트럭의 도착시간 추가
                time += bridge_length;
                break;
            }
            sum += truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        }
        // 다음 트럭의 무게가 다리 무게를 초과할 경우
        else{
            // 시간 계산을 위해 0 추가 (남아있는 트럭을 도착점까지 밀기)
            q.push(0);
        }
    }
    
    return time;
}
