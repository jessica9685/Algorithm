// 2023 카카오 : 택배_배달과_수거하기.cpp 
#include <string>
#include <vector>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int deliver = 0;
    int pickup = 0;
    
    // 뒤에서부터 탐색
    for(int i = n - 1; i >= 0; i--){
        deliver += deliveries[i];
        pickup += pickups[i];
        
        // 음수인 경우: 지나가는 길에 배달/수거 가능 (거리 계산 필요 X)
        while(deliver > 0 || pickup > 0){
            deliver -= cap;
            pickup -= cap;
            
            answer += (i + 1);
        }
    }
    
    return answer * 2;
}
