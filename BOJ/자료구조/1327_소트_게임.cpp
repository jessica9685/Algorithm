// 1327_소트_게임.cpp
#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    scanf("%d %d", &n, &k);
    vector<int> seq(n);
    for(int i = 0; i < n; i++) scanf("%d", &seq[i]);

    vector<int> sorted = seq;
    sort(sorted.begin(), sorted.end());
    // 이미 정렬되어 있으면 종료
    if(seq == sorted) {
        printf("0\n");
        return 0;
    }

    // key: 순열, value: 횟수
    map<vector<int>, int> visited;
    queue<vector<int>> q;
    visited[seq] = 0;
    q.push(seq);

    while(!q.empty()){
        vector<int> cur = q.front();
        q.pop();

        for(int i = 0; i <= n - k; i++){
            vector<int> next = cur;
            for(int j = i, c = i + k - 1; j < i + k, c >= i; j++, c--) next[j] = cur[c];
            
            // 아직 방문 안했으면
            if(visited.count(next) == 0){
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }

    int answer = visited[sorted];
    if(answer == 0) answer = -1; // 정렬 안되면 -1
    printf("%d\n", answer);
    return 0;
}
