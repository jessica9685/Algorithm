// 10217_KCM_Travel.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 101
#define INF 987654321

struct Ticket{
    int dst;
    int cost;
    int time;
};

struct comp{
    bool operator()(Ticket a, Ticket b){
        return a.time > b.time;
    }
};

bool sort_comp(Ticket a, Ticket b){
    return a.time < b.time;
}

int T; // test case
int n, m, k;
int dist[MAX][10001]; // dist[도착지][비용] = 걸린 시간

vector<Ticket> tickets[MAX];

void dijkstra(int start){
    priority_queue<Ticket, vector<Ticket>, comp> pq;
    dist[start][0] = 0;
    pq.push({start, 0, 0});

    while(!pq.empty()){
        Ticket cur = pq.top();
        pq.pop();

        if(dist[cur.dst][cur.cost] < cur.time) continue;

        for(Ticket t : tickets[cur.dst]){
            Ticket next;
            next.dst = t.dst;
            next.cost = cur.cost + t.cost;
            next.time = cur.time + t.time;

            // 비용 초과하면 패스
            if(next.cost > m) continue;
            // 기존 시간이 더 짧으면 패스 
            if(dist[next.dst][next.cost] <= next.time) continue;

            dist[next.dst][next.cost] = next.time;

            // dist 갱신
            for(int i = next.cost + 1; i <= m; i++){
                if(dist[next.dst][i] <= next.time) break;
                dist[next.dst][i] = next.time;
            }
            
            pq.push(next);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &T);

    while(T--){
        scanf("%d %d %d", &n, &m, &k);

        // init
        for(int i = 1; i <= n; i++){
            tickets[i].clear();
            for(int j = 0; j <= m; j++) dist[i][j] = INF;
        }

        for(int i = 0; i < k; i++){
            int u, v, c, d;
            scanf("%d %d %d %d", &u, &v, &c, &d);
            tickets[u].push_back({v, c, d});
        }

        // 시간 오름차순 정렬
        for(int i = 1; i <= n; i++){
            sort(tickets[i].begin(), tickets[i].end(), sort_comp);
        }

        dijkstra(1);

        int ans = INF;
        for(int i = 0; i <= m; i++){
            if(ans > dist[n][i]) ans = dist[n][i];
        }

        if(ans == INF) printf("Poor KCM\n");
        else printf("%d\n", ans);
    }

    return 0;
}
