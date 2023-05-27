// 1647_도시_분할_계획.cpp
// 최소 스패닝 트리 (크루스칼 알고리즘)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000 + 1

struct Road{
    int start, end;
    int cost;
};

int n, m;
vector<Road> path;
int parent[MAX];

// 비용 오름차순 정렬
bool comp(Road a, Road b) { 
    return a.cost < b.cost;
}

int find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    //freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        path.push_back({a, b, c});
    }

    // 유지비 오름차순 정렬
    sort(path.begin(), path.end(), comp);

    // 집합 초기화
    for(int i = 1; i <= n; i++) parent[i] = i;

    // 모든 간선 탐색하며 최소 비용으로 연결하기
    vector<int> min_path; // 연결된 길들의 가중치
    for(int i = 0; i < m; i++) {
        int a = find(path[i].start);
        int b = find(path[i].end);
        int cost = path[i].cost;

        if(a != b) {
            merge(a, b);
            min_path.push_back(cost);
        }
    }

    // 맨 마지막 길만 제외하고 가중치 합 계산
    // 가중치가 가장 큰 길만 제거해 (n - 1) | (1) 로 마을 2개 만듦
    int answer = 0;
    for(int i = 0; i < min_path.size() - 1; i++){
        answer += min_path[i];
    }

    printf("%d\n", answer);
    return 0;
}
