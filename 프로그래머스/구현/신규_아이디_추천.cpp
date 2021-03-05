// 2021 카카오 : 신규_아이디_추천.cpp
#include <string>
#include <vector>
#include <cctype>

using namespace std;


string solution(string new_id) {
    string answer = "";
    
    // step 1
    for(auto &ch : new_id){
        ch = tolower(ch);
    }
    
    // step 2
    for(auto &ch : new_id){
        if(!(ch >= 'a' && ch <= 'z') && !(ch >= '0' && ch <= '9')
          && ch != '-' && ch != '_' && ch != '.') continue;
        else answer.push_back(ch);
    }
    
    // step 3
    string tmp = "";
    for(int i = 0; i < answer.size(); i++){
        if(answer[i] == '.'){
            tmp.push_back('.');
            while(i < answer.size() && answer[i] == '.') i++;
            i--; // for문에서 i++ 한번 더 수행하므로
        }
        else tmp.push_back(answer[i]);
    }
    answer = tmp;
    
    // step 4
    if(answer[0] == '.') answer = answer.substr(1);
    if(answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);
    
    // step 5
    if(answer == "") answer.push_back('a');
    
    // step 6
    if(answer.size() >= 16){
        answer = answer.substr(0, 15);
    }
    if(answer[answer.size() - 1] == '.'){
            answer = answer.substr(0, answer.size() - 1);
        }
    
    // step 7
    if(answer.size() <= 2){
        char add = answer[answer.size() - 1];
        while(answer.size() < 3){
            answer.push_back(add);
        }
    }
    
    return answer;
}
