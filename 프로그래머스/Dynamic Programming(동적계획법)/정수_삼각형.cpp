// 프로그래머스 : 동적계획법 - 정수_삼각형.cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 높이, 내부
int dp[500][500];

int solution(vector<vector<int>> triangle) {
    dp[0][0] = triangle[0][0];
    int answer = dp[0][0];
    int height = triangle.size(); // 높이
    
    for(int i = 1; i < height; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){ // 왼쪽 끝인 경우
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else if(j == i){ // 오른쪽 끝인 경우
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else{ // 가운데일 경우
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
            // 최대값 갱신
            answer = max(answer, dp[i][j]);
        }
    }
    
    return answer;
}
