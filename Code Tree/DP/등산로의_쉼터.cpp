// 등산로의_쉼터.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 5001

int n, m;
int height[MAX];
vector<pair<int, int>> height_sort; // first : index, second : height
vector<int> hiking[MAX];
int dp[MAX]; // i 쉼터에서 갈 수 있는 쉼터 최대 개수

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &height[i]);
        height_sort.push_back({i, height[i]});
        dp[i] = 1;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        
        if(height[a] > height[b]) hiking[a].push_back(b);
        else hiking[b].push_back(a);
    }

    // 높이 기준 내림차순 정렬
    sort(height_sort.begin(), height_sort.end(), comp);

    // 높은 곳에서 낮은 곳으로 이동하면서 개수 count
    for(auto h : height_sort){
        int cur = h.first;
        int cur_h = h.second;

        for(auto next : hiking[cur]){
            // 두 쉼터의 높이가 같은 경우 패스
            if(height[next] == cur_h) continue;
            dp[next] = max(dp[next], dp[cur] + 1);
        }
    }
    
    for(int i = 1; i <= n; i++){
        printf("%d\n", dp[i]);
    }

    return 0;
}
