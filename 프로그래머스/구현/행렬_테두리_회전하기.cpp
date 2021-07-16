// 프로그래머스 : 2021 Dev-Matching - 행렬_테두리_회전하기.cpp
#include <string>
#include <vector>
using namespace std;
#define MAX 101

int matrix[MAX][MAX];
int copied[MAX][MAX];

int rotate(vector<int> query){
    int x1 = query[0];
    int y1 = query[1];
    int x2 = query[2];
    int y2 = query[3];
    
    int mini = 10001;
    
    // x1행, x2행 이동
    for(int j = y1; j < y2; j++){
        matrix[x1][j + 1] = copied[x1][j];
        matrix[x2][j] = copied[x2][j + 1];
    }
    
    // y1, y2열 이동
    for(int i = x1; i < x2; i++){
        matrix[i + 1][y2] = copied[i][y2];
        matrix[i][y1] = copied[i + 1][y1];
    }
    
    // 최솟값 구하기
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            if(i == x1 || i == x2 || j == y1 || j == y2){
                mini = min(mini, matrix[i][j]);
            }
        }
    }
    
    return mini;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // 초기 행렬 상태
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            matrix[i][j] = (i - 1) * columns + j;
        }
    }
    
    for(int c = 0; c < queries.size(); c++){
        // 행렬 복사
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= columns; j++){
                copied[i][j] = matrix[i][j];
            }
        }  
        
        int ans = rotate(queries[c]);
        answer.push_back(ans);
    }
    
    return answer;
}
