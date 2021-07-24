// 2021 카카오 채용연계형 인턴십 : 거리두기_확인하기.cpp
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 맨해튼 거리 (2 이하면 ㄴㄴ)
int dist(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int space[5][5];
bool visited[5][5] = {false, };
int dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dx[8] = {1, -1, 0, 0, -1, 1, -1, 1};

int dy2[4] = {0, 0, 2, -2};
int dx2[4] = {-2, 2, 0, 0};

bool distancing(int y, int x){
    // 8방향 탐색
    for(int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        // 범위 벗어나면 continue
        if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
        if(space[ny][nx] == 1){ // 응시자가 있는 경우
            if(dist(y, x, ny, nx) == 1) { // 거리가 1이면 false
                return false;
            }
            else{ // 거리가 2인 경우
                int ty1 = y + dy[i], tx1 = x;
                int ty2 = y, tx2 = x + dx[i];
                
                // 두 응시자 사이에 2개의 파티션이 없으면 false
                if(!(space[ty1][tx1] == -1 && space[ty2][tx2] == -1)) {
                    return false;
                }
            }
        }
    }
    
    // 직선거리가 2인 경우 탐색
    for(int i = 0; i < 4; i++){
        int ny = y + dy2[i];
        int nx = x + dx2[i];
        
        // 거리 2에 응시자가 있으면
        if(space[ny][nx] == 1){
            int ty = y + (dy2[i] / 2);
            int tx = x + (dx2[i] / 2);
            
            // 사이에 파티션이 없으면 false
            if(space[ty][tx] != -1) return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // 대기실별로 순회
    for(auto place : places){
        // 대기실 내 순회
        for(int i = 0; i < place.size(); i++){
            for(int j = 0; j < place[i].size(); j++){
                if(place[i][j] == 'P'){ // 응시자 = 1
                    space[i][j] = 1;
                }
                else if(place[i][j] == 'O'){ // 빈 테이블 = 0
                    space[i][j] = 0;
                }
                else if(place[i][j] == 'X'){ // 파티션 = -1
                    space[i][j] = -1;
                }
            }
        }
        
        bool isOK = true;
        for(int i = 0; i < 5; i++){
            if(!isOK) break;
            for(int j = 0; j < 5; j++){
                if(space[i][j] == 1){
                   if(!distancing(i, j)){
                       isOK = false;
                       break;
                   } 
                }
            }
        }
        
        if(isOK) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}
