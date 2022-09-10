// 2022 카카오 인턴십 : 코딩_테스트_공부.cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 151
#define INF 10000

int solution(int alp, int cop, vector<vector<int>> problems) {
    // 각 문제를 푸는데 필요한 알고력, 코딩력 최댓값
    int max_alp = 0, max_cop = 0;
    for(auto& p : problems){
        if(max_alp < p[0]) max_alp = p[0];
        if(max_cop < p[1]) max_cop = p[1];
    }
    // max_alp, max_cop가 초기값보다 낮은 경우도 존재 => 더 작은 값으로 수정
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);
    
    // dp[alp][cop]: 해당 코딩력, 알고력을 달성하는데 필요한 시간 (INF로 초기화)
    // 주의! {INF, }로 초기화하면 초기화 안됨... 안전하게 for문으로 완전탐색하자
    int dp[MAX][MAX];
    for(int i = 0; i <= max_alp; i++){
        for(int j = 0; j <= max_cop; j++) dp[i][j] = INF;
    }
    dp[alp][cop] = 0; // 초기값을 달성하는데 필요한 시간 = 0
    
    for(int a = alp; a <= max_alp; a++){
        for(int c = cop; c <= max_cop; c++){
            // 문제 안풀고 알고력, 코딩력 1씩 올리기
            if(a + 1 <= max_alp) dp[a + 1][c] = min(dp[a + 1][c], dp[a][c] + 1);
            if(c + 1 <= max_cop) dp[a][c + 1] = min(dp[a][c + 1], dp[a][c] + 1);
            
            // 모든 문제 순회
            for(auto &p : problems){
                int alp_req = p[0], cop_req = p[1];
                int alp_rwd = p[2], cop_rwd = p[3];
                int cost = p[4];
                
                // 현재 알고력, 코딩력으로 해당 문제를 풀 수 있으면
                if(a >= alp_req && c >= cop_req){
                    // 증가한 코딩력, 알고력이 max를 넘어서면 dp를 목표치로 조정해서 넣기
                    if(a + alp_rwd > max_alp && c + cop_rwd > max_cop){ // 둘 다 목표치를 넘었을 때
                        dp[max_alp][max_cop] = min(dp[max_alp][max_cop], dp[a][c] + cost);
                    }
                    else if(a + alp_rwd > max_alp){ // 알고력이 목표치를 넘었을 때
                        dp[max_alp][c + cop_rwd] = min(dp[max_alp][c + cop_rwd], dp[a][c] + cost);
                    }
                    else if(c + cop_rwd > max_cop){ // 코딩력이 목표치를 넘었을 때
                        dp[a + alp_rwd][max_cop] = min(dp[a + alp_rwd][max_cop], dp[a][c] + cost);
                    }
                    else if(a + alp_rwd <= max_alp && c + cop_rwd <= max_cop){ // 둘 다 목표치 이하일 때
                        dp[a + alp_rwd][c + cop_rwd] = min(dp[a + alp_rwd][c + cop_rwd], dp[a][c] + cost);
                    }
                }
            }
        }
    }
    return dp[max_alp][max_cop];
}
