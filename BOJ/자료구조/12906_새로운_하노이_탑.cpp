// 12906_새로운_하노이_탑.cpp
#include <bits/stdc++.h>
using namespace std;

array<string, 3> sticks; // 막대 A, B, C
int circle_cnt[3] = {0, }; // 각 원판의 개수

int main(){
    for(int i = 0; i < 3; i++){
        int cnt;
        scanf("%d", &cnt);
        sticks[i] = "";

        while(cnt--){
            char circle;
            scanf(" %c", &circle);
            sticks[i].push_back(circle); // 막대 상태 저장
            circle_cnt[circle - 'A']++; // 원판 개수 추가
        }
    }

    /* BFS */
    // key: 막대 A, B, C의 상태(string 3개)
    // value: 몇 번째 이동만에 해당 상태에 도달했는지 (0이면 방문 X)
    map<array<string, 3>, int> visited;
    queue<array<string, 3>> q;
    q.push(sticks);
    visited[sticks] = 0;

    while(!q.empty()){
        array<string, 3> cur = q.front();
        q.pop();

        // 각 막대들 탐색
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == j) continue;
                // 막대에 원판이 없으면 패스
                if(cur[i].size() == 0) continue;
                
                // i -> j로 원판 이동
                array<string, 3> next = cur;
                next[j].push_back(next[i].back());
                next[i].pop_back();

                // 아직 방문 안했으면
                if(visited.count(next) == 0){
                    visited[next] = visited[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    // 정답일 때 막대들 상태 (key)
    array<string, 3> ans_state;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < circle_cnt[i]; j++){
            ans_state[i] += 'A' + i;
        }
    }

    // 해당 key의 value가 정답
    int answer = visited[ans_state];
    printf("%d\n", answer);
    return 0;
}
