// 1525_퍼즐.cpp
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

string init;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int bfs(string start){
    queue<pair<int, string>> q; // first: 횟수, second: 보드 상태
    unordered_set<string> visited; // 방문표시
    visited.insert(start);
    q.push({0, start});

    while(!q.empty()){
        int cnt = q.front().first;
        string cur = q.front().second;
        q.pop();

        // 목표 상태를 만들면 종료
        if(cur == "123456780") return cnt;

        // 0의 위치 찾기
        int zero = cur.find('0');
        int y = zero / 3;
        int x = zero % 3;

        for(int d = 0; d < 4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(ny < 0 || nx < 0 || ny >= 3 || nx >= 3) continue;

            // 0(빈칸)과 다른 숫자의 위치 swap
            string next = cur;
            swap(next[3 * y + x], next[3 * ny + nx]);
            // 아직 방문 안했으면
            if(visited.count(next) == 0){
                visited.insert(next);
                q.push({cnt + 1, next});
            }
        }
    }

    return -1;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            char num;
            scanf(" %c", &num);
            init += num;
        }
    }

    int answer = bfs(init);
    printf("%d\n", answer);
    return 0;
}
