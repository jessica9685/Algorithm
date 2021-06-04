// 프로그래머스 : 정렬 - K번째수.cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto c : commands){
        int i = c[0];
        int j = c[1];
        int k = c[2];
        
        vector<int> new_array;
        for(int idx = i - 1; idx < j; idx++){
            new_array.push_back(array[idx]);
        }
        
        sort(new_array.begin(), new_array.end());
        answer.push_back(new_array[k - 1]);
    }
    
    return answer;
}
