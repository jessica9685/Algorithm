// 프로그래머스 : 힙(Heap) - 디스크_컨트롤러.cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    // 소요시간이 같을 경우
    if(a[1] == b[1]) {
        return a[0] < b[0]; // 더 빠른 요청부터 처리
    }
    else { // 소요시간이 짧은 요청부터 처리
        return a[1] < b[1]; 
    }
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int start = 0; // 작업을 시작할 수 있는 시간
    int time = 0; // 대기+소요 시간
    
    sort(jobs.begin(), jobs.end(), compare);
    int cnt = jobs.size();
    
    while(!jobs.empty()){
        for(int i = 0; i < jobs.size(); i++){
            // 작업 요청 시간이 시작 시간보다 빠른 경우
            if(jobs[i][0] <= start){
                time += (start - jobs[i][0]) +  jobs[i][1];
                start += jobs[i][1];
                jobs.erase(jobs.begin() + i);
                break;
            }
            // 모든 작업의 요청 시간이 시작시간보다 느린 경우
            if(i == jobs.size() - 1){
                start++; // 시작 시간을 뒤로 조정
            }
        }
    }
    
    answer = time / cnt;
    
    return answer;
}
