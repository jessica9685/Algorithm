// 1939_중량제한.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001

int parent[MAX];
int n, m; // n : 섬 개수, m : 다리 개수
vector<pair<int, pair<int,int>>> bridges;; // first: 제한 무게, second : 다리가 연결된 두 섬
int f1, f2; // 공장 위치

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first > b.first;
}

int find(int a){
	if(parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

void union_set(int a, int b){
	int pa = find(a);
	int pb = find(b);
	
    parent[pa] = pb;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){ // 다리 정보
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        bridges.push_back({c, {a, b}});
    }
    scanf("%d %d", &f1, &f2);

    // 부모 초기화
    for(int i = 1; i <= n; i++) parent[i] = i;

    // 무게가 큰 순서대로 정렬 (내림차순)
    sort(bridges.begin(), bridges.end(), comp);

    int ans = 0;
    for(auto bridge : bridges){
        // 이어진 섬끼리 union
        union_set(bridge.second.first, bridge.second.second);

        // 공장 2개가 서로 이어지면
        if(find(f1) == find(f2)){
            // 중량 제한 최소값 반환
            ans = bridge.first;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
