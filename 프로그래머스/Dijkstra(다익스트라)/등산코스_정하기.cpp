// 2022 카카오 인턴십 : 등산코스_정하기.cpp
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 50001
#define INF 10000001

vector<pair<int, int>> path[MAX]; // first: end, second: weight
bool gate[MAX]; // 출입구면 true
bool summit[MAX]; // 산봉우리면 true
int intensity[MAX]; // intensity[i]: start ~ i까지의 최소 intensity

void dijkstra(vector<int> gates, int n){
    // intensity 초기화
    for(int i = 1; i <= n; i++) intensity[i] = INF;
    
    // first: 현재까지의 intensity, second: 현재 위치
    priority_queue<pair<int, int>> pq;
    // 출입구의 intensity는 0 -> 모두 start로 pq에 push
    for(auto g : gates) {
        pq.push({0, g});
        intensity[g] = 0;
    }
    
    while(!pq.empty()){
        int cur_intensity = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        // 다음 노드 탐색
        for(auto node : path[cur]){
            int next = node.first;
            int next_w = node.second;
            
            // intensity의 최솟값 갱신
            if(intensity[next] > max(cur_intensity, next_w)){
                intensity[next] = max(cur_intensity, next_w);
                pq.push({-intensity[next], next});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    // gate, summit 배열 초기화
    for(int i = 1; i <= n; i++){
        gate[i] = false;
        summit[i] = false;
    }
    for(auto &g : gates) gate[g] = true;
    for(auto &s : summits) summit[s] = true;
    
    // 등산로 vector 생성
    for(auto &p : paths){
        int start = p[0];
        int end = p[1];
        int w = p[2];
        
        // 출입구는 나가는 방향만, 산봉우리는 들어가는 방향만 저장
        if(gate[start] || summit[end]) path[start].push_back({end, w});
        else if(summit[start] || gate[end]) path[end].push_back({start, w});
        else{ // 나머지는 모두 양방향
            path[start].push_back({end, w});
            path[end].push_back({start, w});
        }
    }
    
    // 모든 출입구에 대한 다익스트라 수행
    dijkstra(gates, n);
    // 산봉우리 오름차순 정렬 (intensity가 같은 경우 산봉우리 오름차순으로 출력)
    sort(summits.begin(), summits.end());
    
    // 최소 intensity 찾기
    vector<int> answer = {0, INF};
    for(auto &s : summits){
        if(answer[1] > intensity[s]){
            answer[1] = intensity[s];
            answer[0] = s;
        }
    }
    return answer;
}
