// 1251_하나로.cpp
// 크루스칼
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 1001

typedef long long ll;

typedef struct Edge{
    int start, end;
    ll len;
}Edge;

int n;
double taxRate;
ll dx[MAX], dy[MAX];
vector<Edge> graph;
ll dist[MAX][MAX];
int parent[MAX];

// 초기화
void init(){
    // 집합 배열 초기화
    for(int i = 1; i <= n; i++) parent[i] = i;

    // 각 정점간 거리 구하기
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dist[i][j] = 0;
            else{
                ll x = dx[i] - dx[j];
                ll y = dy[i] - dy[j];
                dist[i][j] = x * x + y * y;
            }
        }
    }

    // 각 간선을 그래프로 구현
    graph.clear();
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            graph.push_back({i, j, dist[i][j]});
        }
    }
}

// 집합 찾기
int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

// 집합 합치기
void merge(int a, int b){
    a = find(a);
    b = find(b);
    // 섬 번호가 더 작은 방향으로 합치기
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool comp(Edge a, Edge b){
    return a.len < b.len;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> dx[i];
        for(int i = 1; i <= n; i++) cin >> dy[i];
        cin >> taxRate;

        init(); // 초기화

        // 가중치 기준 오름차순 정렬
        sort(graph.begin(), graph.end(), comp);

        double answer = 0.0;
        for(auto edge : graph){
            int pa = find(edge.start);
            int pb = find(edge.end);
            ll len = edge.len;
            
            if(pa != pb){
                merge(pa, pb);
                answer += (len * taxRate);
            }
        }

        cout << "#" << tc << " " << (ll)round(answer) << "\n";
    }
    return 0;
}
