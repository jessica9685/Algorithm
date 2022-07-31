// 연습문제 : 124_나라의_숫자.cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string str = "";
    while(n > 0){
        // 10진법 -> 3진법
        int q = n / 3;
        int r = n % 3;
        
        // 나머지가 0이면
        if(r == 0){
            // 몫을 -1하고 나머지를 0 대신 4로 치환
            q -= 1;
            r = 4;
        }
        str += (r + '0');
        n = q;
    }
    
    string answer = "";
    // reverse
    for(int i = str.size() - 1; i >= 0; i--) answer += str[i];
    return answer;
}
