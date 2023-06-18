// 1765_닭싸움_팀_정하기.cpp
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

int n, m;
vector<int> friends[MAX], enemies[MAX];
bool in_team[MAX] = {false, };

void dfs(int cur){
    in_team[cur] = true;

    // 친구를 팀에 추가
    for(auto f : friends[cur]){
        if(!in_team[f]) dfs(f);
    }

    // 원수의 원수를 팀에 추가
    for(auto e : enemies[cur]){
        for(auto f : enemies[e]){
            if(!in_team[f]) dfs(f);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        char ch;
        int p, q;
        scanf(" %c %d %d", &ch, &p, &q);

        if(ch == 'F'){
            friends[p].push_back(q);
            friends[q].push_back(p);
        }
        else{
            enemies[p].push_back(q);
            enemies[q].push_back(p);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!in_team[i]){
            dfs(i);
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
