// 프로그래머스 : DFS/BFS - 네트워크.cpp
#include <string>
#include <vector>

using namespace std;

void dfs(int start, vector<vector<int>> &computers, vector<bool> &visited, int n){
    visited[start] = true;
    for(int i = 0; i < n; i++){
        // i번 컴퓨터를 방문했고, start -> i가 연결되어 있으면
        if(!visited[i] && computers[start][i]){
            dfs(i, computers, visited, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            answer++;
            dfs(i, computers, visited, n);
        }
    }
    
    return answer;
}
