// 프로그래머스 - Greedy(탐욕법) : 단속카메라.cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    // 진입 지점 기준 오름차순 정렬
    sort(routes.begin(), routes.end());
    
    int standard = routes[0][1]; // 카메라 설치 기준(진출 지점)
    int answer = 1; // 카메라 개수
    
    for(int i = 1; i < routes.size(); i++){
        // 이전 차의 진출 지점보다 다음 차의 진입 지점이 앞인 경우
        // (두 차의 경로가 겹치는 경우)
        if(standard >= routes[i][0]){
            standard = min(standard, routes[i][1]);
        }
        else{
            answer++;
            standard = routes[i][1];
        }
    }
    
    return answer;
}
