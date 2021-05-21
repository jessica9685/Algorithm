// 프로그래머스 : Greedy(탐욕법) - 체육복.cpp
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 1: 체육복 있음 / 2: 체육복 여벌 있음 / 0: 체육복 잃어버림
    vector<int> students(n, 1);
    
    for(auto l : lost){ // 체육복 잃어버린 경우
        students[l - 1]--;
    }
    
    for(auto r : reserve){ // 체육복 여벌 있는 경우
        students[r - 1]++; 
    }
    
    for(int i = 0; i < n; i++){
        if(students[i] == 0){
            if(i != 0 && students[i - 1] == 2){
                students[i] = 1;
                students[i - 1] = 1;
            }
            else if(i != n - 1 && students[i + 1] == 2){
                students[i] = 1;
                students[i + 1] = 1;
            }   
        }
    }
    
    for(auto s : students){
        if(s > 0) answer++;
    }
    
    return answer;
}
