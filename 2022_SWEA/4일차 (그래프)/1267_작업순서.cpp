// 1267_작업순서.cpp
// 위상정렬
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T = 10;
    for(int tc = 1; tc <= T; tc++){
        int v, e;
        cin >> v >> e;

        vector<int> graph[MAX];
        int indegree[MAX] = {0, }; // 진입 차수 (완료해야하는 작업 수)
        for(int i = 0; i < e; i++){
            int start, end;
            cin >> start >> end;
            graph[start].push_back(end);
            indegree[end]++;
        }

        vector<int> answer;
        queue<int> q;
        // 진입차수가 0인 작업 push
        for(int i = 1; i <= v; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            // 현재 정점 경로에 추가
            answer.push_back(cur);

            // 다음 정점 탐색
            for(auto next : graph[cur]){
                // 진입 차수가 0이면 
                if(--indegree[next] == 0) q.push(next);
            } 
        }

        cout << "#" << tc << " ";
        for(auto work : answer) cout << work << " ";
        cout << "\n";
    }
    return 0;
}
