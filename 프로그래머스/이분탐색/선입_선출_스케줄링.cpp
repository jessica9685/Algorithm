// 연습문제 : 선입_선출_스케줄링.cpp
// 파라메트릭 서치 (Parametric Search)
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> cores) {
    // 작업 수가 코어보다 작거나 같으면 n 리턴
    if(n <= cores.size()) return n;
    
    int s = cores.size();
    // 작업 1개를 처리하는데 필요한 최소/최대 시간
    int minTime = 100001;
    int maxTime = 0;
    for(int core : cores){
        minTime = min(minTime, core);
        maxTime = max(maxTime, core);
    }
    
    // 모든 작업을 수행하는데 걸리는 최소/최대 시간
    int left = minTime * (n / s);
    int right = maxTime * n;
    
    // 이분탐색 (Parametric Search)
    while(left <= right){
        int mid = (left + right) / 2;
        int prev = s; // mid 전까지 수행한 작업 수
        int cur = 0; // mid에 수행한 작업 수
        
        // mid까지 수행한 작업 수 구하기
        for(int core : cores){
            prev += (mid / core);
            
            if(mid % core == 0){ // 나누어 떨어지면
                prev--;
                cur++; // 현재 작업량에 추가
            }
        }
        
        // mid까지 수행한 작업 수
        int total = prev + cur;
        
        // mid 전까지 수행한 작업량이 n을 넘어서면 왼쪽으로 이동
        if(prev >= n) right = mid - 1;
        // mid까지 수행한 작업량이 n보다 작으면 오른쪽으로 이동
        else if(total < n) left = mid + 1;
        // mid까지 수행한 작업량이 n보다 크거나 같은 경우
        else{
            // 마지막 작업을 수행하는 코어 탐색
            for(int i = 0; i < s; i++){
                if(mid % cores[i] == 0) prev++;
                if(prev == n) return i + 1;
            }
        }
    }
}
