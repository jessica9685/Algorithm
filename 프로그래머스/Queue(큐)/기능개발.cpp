// 프로그래머스 : 스택/큐 - 기능개발.cpp
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int func = progresses.size();
    queue<int> q;
    
    // 각 기능들의 배포일을 큐에 저장
    for(int i = 0; i < func; i++){
        int days = (int)ceil((double)(100 - progresses[i]) / (double)speeds[i]);
        q.push(days);
    }
    
    int cnt = 0;
    int bound = q.front(); // 기준 배포일
    
    while(!q.empty()){
        // 각 기능이 bound 내에 완료되면 count
        if(q.front() <= bound){
            cnt++; 
            q.pop();
        }
        else {
            answer.push_back(cnt);
            cnt = 0;
            bound = q.front();
        }
    }
    
    // 마지막 남은 기능 배포 개수 추가
    answer.push_back(cnt);
    return answer;
}
