// 연습문제 : 가장_큰_정사각형_찾기.cpp
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board) {
    int row = board.size();
    int col = board[0].size();
    int answer = 0;
    
    // 2x2 이하인 표일 때
    if(row < 2 || col < 2) {
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 1) return 1;
            }
        }
        return 0;
    }
    
    // 가장 큰 정사각형 변의 길이 구하기
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            // 값이 1 이상일 때
            if(board[i][j] > 0){
                // ([i - 1][j], [i][j - 1], [i - 1][j - 1]의 최솟값) + 1
                board[i][j] = min(board[i - 1][j], board[i][j - 1]);
                board[i][j] = min(board[i][j], board[i - 1][j - 1]) + 1;
            }
            answer = max(answer, board[i][j]);
        }
    }
    
    return answer * answer;
}
