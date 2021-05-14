// 프로그래머스 : 동적계획법 - 등굣길.cpp
#include <cstring>
#include <vector>
using namespace std;
#define MAX 101

int solution(int m, int n, vector<vector<int>> puddles) {
    // (a, b)까지의 경로 수
    int routes[MAX][MAX];
    // 1로 초기화
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) routes[i][j] = 1;
    }
    
    // 물웅덩이가 있는 곳의 경로 개수는 0
    for(int i = 0; i < puddles.size(); i++){
        int y = puddles[i][0]; // column
        int x = puddles[i][1]; // row
        
        // 물웅덩이가 있는 곳 = 0
        routes[x][y] = 0;
        
        // 물웅덩이가 모서리에 있을 경우 -> 그 오른쪽/아래부터 끝까지 모두 0
        if(x == 1){ // 1행일 경우 (1 row)
            for(int j = y; j <= m; j++) routes[1][j] = 0;
        }
        if(y == 1){ // 1열일 경우 (1 col)
            for(int j = x; j <= n; j++) routes[j][1] = 0;
        }
    }
    
    // 경로 개수 계산
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            // 해당 구간에 물웅덩이가 없으면
            if(routes[i][j] != 0){ 
                routes[i][j] = (routes[i - 1][j] + routes[i][j - 1]) % 1000000007;
            }
        }
    }
    
    return routes[n][m];
}
