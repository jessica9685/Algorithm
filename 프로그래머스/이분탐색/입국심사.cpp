// 프로그래머스 : 이분탐색 - 입국심사.cpp
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    ll answer = 0;
    ll left = 1; // 최소 시간
    ll right = (ll)times[times.size() - 1] * (ll)n; // 최대 시간
    
    while(left <= right){
        ll people = 0;
        ll mid = (left + right) / 2; // 평균(중간)
        
        // 평균 시간까지 심사할 수 있는 최대 인원 수
        for(auto t : times) people += (mid / t);
        
        if(n <= people){ // 목표 인원 수보다 많을 경우
            answer = mid;
            right = mid - 1;
        }
        else{ // 목표 인원 수보다 적을 경우
            left = mid + 1;
        }
    }
    
    return answer;
}
