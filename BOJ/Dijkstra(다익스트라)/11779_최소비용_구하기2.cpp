// 11779_최소비용_구하기2.cpp
#include <bits/stdc++.h>
using namespace std;
#define INF 100000001
#define MAX 1001

struct Node{
    int end, cost;
};

int n, m;
vector<Node> bus[MAX];

void dijkstra(int start, int end){
    // init
    int dist[MAX], parent[MAX];
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        parent[i] = i;
    }
    
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if(dist[cur] < cur_dist) continue;

        for(auto next : bus[cur]){
            if(dist[next.end] > dist[cur] + next.cost){
                dist[next.end] = dist[cur] + next.cost;
                parent[next.end] = cur; // 부모노드 갱신
                pq.push({-dist[next.end], next.end});
            }
        }
    }

    // 최소비용
    printf("%d\n", dist[end]);

    // 경로 추적
    vector<int> ans;
    int cur = end;
    ans.push_back(cur);
    while(cur != start){
        if(parent[cur] != cur) {
            ans.push_back(parent[cur]);
            cur = parent[cur];
        }
    }

    printf("%d\n", ans.size());
    for(int i = ans.size() - 1; i >= 0; i--){
        printf("%d ", ans[i]);
    }
    printf("\n");
}


int main(){
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        bus[start].push_back({end, cost});
    }
    int src, dst;
    scanf("%d %d", &src, &dst);

    dijkstra(src, dst);
    return 0;
}
