// 프로그래머스 : 해시(Hash) - 전화번호_목록.cpp
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {   
    bool answer = true;
    unordered_map<string, int> hash;
    
    // 각 번호의 부분문자열을 해시에 삽입
    for(auto num : phone_book){
        for(int i = 1; i <= num.size(); i++){
            string s = num.substr(0, i);
            hash[s]++;
        }
    }
    
    for(auto num : phone_book){
        if(hash[num] > 1) {
            answer = false;
            break;
        }
    }
    
    return answer;
}
