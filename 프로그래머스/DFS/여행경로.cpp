// 프로그래머스 : DFS/BFS - 여행경로.cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;

void dfs(string start, int cnt, vector<vector<string>> &tickets, vector<string> &answer, vector<string> &tmp){
    tmp.push_back(start);
    // 모든 티켓을 다 사용한 경우
    // 경로가 여러개일 수 있으므로 제일 처음에 나온 경로만 리턴
    if(cnt == tickets.size() && answer.empty()){
        answer = tmp;
        return;
    }
    for(int i = 0; i < tickets.size(); i++){
        // 출발지가 start이고, 해당 티켓을 아직 사용하지 않았으면
        if(tickets[i][0] == start && !visited[i]){
            visited[i] = true;
            dfs(tickets[i][1], cnt + 1, tickets, answer, tmp);
            visited[i] = false;
        }
    }
    tmp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, tmp;
    visited.resize(tickets.size(), false);
    // 알파벳 순서대로 정렬  
    sort(tickets.begin(), tickets.end());
    dfs("ICN", 0, tickets, answer, tmp);
    
    return answer;
}
