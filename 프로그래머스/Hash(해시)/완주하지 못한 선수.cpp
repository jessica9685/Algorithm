// 프로그래머스 : 해시(Hash) - 완주하지 못한 선수.cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    /* 정렬 */
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < completion.size(); i++){
        if(completion[i] != participant[i]){
            return participant[i];
        }
    }
    
    // 끝까지 일치할 경우 맨 마지막꺼가 불일치
    return *(participant.end() - 1);
}
