// 프로그래머스 : 동적계획법 - 도둑질.cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000

int solution(vector<int> money) {
    int dp[MAX][2];
    int n = money.size(); // 집 개수
    
    // 첫번째 집을 선택한 경우
    dp[0][1] = money[0];
    dp[1][1] = max(money[0], money[1]); // 그냥 0이라고 하면 테케 1번 틀림
    
    // 첫번째 집을 선택하지 않은 경우
    dp[0][0] = 0;
    dp[1][0] = money[1];
    
    for(int i = 2; i < n; i++){
        for(int sel = 0; sel < 2; sel++){
            if(sel == 0){ // 1번째 집 선택 X
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + money[i]);    
            }
            else{ // 1번째 집 선택
                if(i == n - 1) continue;
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + money[i]);
            }
        }
    }
    
    int answer = max(dp[n - 2][1], dp[n - 1][0]);
    return answer;
}
