// 프로그래머스 - Greedy(탐욕법) : 구명보트.cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    // 몸무게 오름차순 정렬
    sort(people.begin(), people.end());
    
    int answer = 0;
    int idx = 0;
    
    while(people.size() > idx){
        // (최소 몸무게 + 최대 몸무게)가 limit 이하인지 확인
        int sum = people.back() + people[idx];
        // limit 이하면 앞부분 인덱스 증가 (2명 태움)
        if(sum <= limit) idx++; 
        people.pop_back(); // 최대 몸무게는 무조건 태움
        answer++;
    }

    return answer;
}
