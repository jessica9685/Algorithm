// 프로그래머스 : Greedy(탐욕법) - 조이스틱.cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size(); // 문자열 길이
    
    string tmp;
    tmp.assign(n, 'A');
    
    int cur = 0; // 커서 위치
    
    while(tmp != name){
        // 커서(좌우이동) 이동 횟수
        for(int i = 0; i < n; i++){
            int right = (cur + i) % n; // 오른쪽으로 i만큼 이동 위치
            int left = cur - i; // 왼쪽
            if(left < 0) left += n;
            
            // 오른쪽/왼쪽 이동 횟수 중 더 작은 방향으로 이동
            if(name[right] != tmp[right]){
                answer += i;
                cur = right;
                break;
            }
            else if(name[left] != tmp[left]){
                answer += i;
                cur = left;
                break;
            }
        }
        
        // 알파벳 변경(상하이동) 횟수 
        tmp[cur] = name[cur];
        answer += min('Z' + 1 - tmp[cur], tmp[cur] - 'A');
    }
    
    return answer;
}
