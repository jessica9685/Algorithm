// 2023 카카오 : 미로_탈출_명령어.cpp
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int dist = abs(x - r) + abs(y - c); // 최단 이동 거리
    k -= dist;
    // k가 0보다 작거나 홀수이면 이동 불가능
    if(k < 0 || k % 2 != 0) return "impossible";
    
    int dir[4] = {0, 0, 0, 0}; // d(down), l(left), r(right), u(up)
    
    if(x > r) dir[3] = x - r; // up
    else dir[0] = r - x; // down
    
    if(y > c) dir[1] = y - c; // left
    else dir[2] = c - y; // right
    
    // d, l, r, u 순으로 이동
    string answer = ""; 
    // d
    for(int i = 0; i < dir[0]; i++) answer += "d";
    dir[0] = min(k / 2, n - (x + dir[0])); // 범위 내에서 이동할 수 있는 down 최대값
    for(int i = 0; i < dir[0]; i++) answer += "d";
    dir[3] += dir[0]; // 추가로 이동한 d만큼 u 추가
    k -= (2 * dir[0]);
    
    // l
    for(int i = 0; i < dir[1]; i++) answer += "l";
    dir[1] = min(k / 2, y - dir[1] - 1); // 범위 내에서 이동할 수 있는 left 최대값
    for(int i = 0; i < dir[1]; i++) answer += "l";
    dir[2] += dir[1]; // 추가로 이동한 l만큼 r 추가
    k -= (2 * dir[1]);
    
    // k가 남는 경우 'rl' 추가 (뒤에 r, u가 더 붙기 때문에 lr이 아닌 rl 추가)
    for(int i = 0; i < k / 2; i++) answer += "rl";
    // r
    for(int i = 0; i < dir[2]; i++) answer += "r";
    // u
    for(int i = 0; i < dir[3]; i++) answer += "u";
    
    return answer;
}
