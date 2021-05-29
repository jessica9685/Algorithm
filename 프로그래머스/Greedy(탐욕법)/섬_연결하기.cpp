// 프로그래머스 - Greedy(탐욕법) : 섬_연결하기.cpp
// 크루스칼 알고리즘
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// i번째 노드의 부모 노드를 저장한 배열
int parents[101];

// node의 부모 노드를 불러오는 함수
int getParent(int node){
    if(parents[node] == node) return node;
    return parents[node] = getParent(parents[node]);
}

// cost 기준 오름차순 정렬
bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 부모노드 초기화
    for(int i = 0; i < n; i++) parents[i] = i;
    
    // cost 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < costs.size(); i++){
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        // 부모가 다르면 (사이클이 만들어지지 X)
        if(start != end){
            answer += cost; // 다리 추가
            parents[end] = start;
        }
    }
    
    return answer;
}
