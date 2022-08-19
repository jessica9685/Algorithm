// 연습문제 : 땅따먹기.cpp
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int n = land.size(); // 행 개수
    int dp[100000][4] = { 0, }; // dp[r][c] : r행 c열까지 왔을 때 최대 점수
    // dp 초기화
    for(int j = 0; j < 4; j++) dp[0][j] = land[0][j];
    
    // 각 행/열에서의 최댓값 구하기
    for(int i = 1; i < n; i++){
        dp[i][0] = max(max(dp[i - 1][1], dp[i - 1][2]), dp[i - 1][3]) + land[i][0];
        dp[i][1] = max(max(dp[i - 1][0], dp[i - 1][2]), dp[i - 1][3]) + land[i][1];
        dp[i][2] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][3]) + land[i][2];
        dp[i][3] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + land[i][3];
    }
    
    int answer = 0;
    for(int j = 0; j < 4; j++) answer = max(answer, dp[n - 1][j]);
    return answer;
}
