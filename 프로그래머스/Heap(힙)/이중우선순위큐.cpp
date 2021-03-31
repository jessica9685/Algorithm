// 프로그래머스 : 힙(Heap) - 이중우선순위큐.cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> q;
    
    for(auto op : operations){
        if(op[0] == 'I'){
            q.push_back(stoi(op.substr(2)));
        }
        else if(op[0] == 'D'){
            if(q.empty()) continue;
            if(op[2] == '1'){
                int max_idx = max_element(q.begin(), q.end()) - q.begin();
                q.erase(q.begin() + max_idx);
            }
            else if(op[2] == '-'){
                int min_idx = min_element(q.begin(), q.end()) - q.begin();
                q.erase(q.begin() + min_idx);
            }
        }
    }
    
    
    if(q.empty()) answer = {0, 0};
    else{
        int min = *min_element(q.begin(), q.end());
        int max = *max_element(q.begin(), q.end());
        answer.push_back(max);
        answer.push_back(min);
    }
    
    return answer;
}
