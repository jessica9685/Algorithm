// 프로그래머스 : 해시(Hash) - 위장.cpp
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // string: 의상 종류, int: 해당 종류의 의상 개수
    unordered_map<string, int> hash_map;
    for(auto c : clothes){
        hash_map[c[1]]++;
    }
    
    for(auto c : hash_map){
        answer *= (c.second + 1);
    }
    
    return answer - 1;
}
