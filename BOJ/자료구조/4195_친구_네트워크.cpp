// 4195_친구_네트워크.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 200002 // 관계의 수(F) 최대 10만 * 2

int F;
int parent[MAX];
int cnt[MAX]; // 네트워크에 포함된 친구 수

/* union - find */
// 부모 찾기
int find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

// 합집합
void unionSet(int a, int b){
    int pa = find(a);
    int pb = find(b);

    // 부모가 서로 다르면
    if(pa != pb){
        // 더 숫자가 많은 쪽이 부모로 ㄱ 
        if(cnt[pa] < cnt[pb]) swap(pa, pb);
        cnt[pa] += cnt[pb];
        parent[pb] = pa;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, F;
    cin >> tc;

    while(tc--){
        cin >> F;

        // 초기화
        for(int i = 0; i < MAX; i++){
            parent[i] = i;
            cnt[i] = 1;
        }

        // key: 이름, value: 노드 번호 (parent index에 대응)
        // key가 string이기 때문에 map을 이용해 string을 int index로 치환
        map<string, int> friends;
        int nodeNum = 1;

        while(F--){
            string f1, f2;
            cin >> f1 >> f2;

            // 아직 map에 key가 존재하지 않으면 노드 번호로 value를 지정
            if(!friends.count(f1)) friends[f1] = nodeNum++;
            if(!friends.count(f2)) friends[f2] = nodeNum++;

            // 집합 합치기
            unionSet(friends[f1], friends[f2]);

            // 각 친구의 부모 찾기
            int p1 = find(friends[f1]);
            int p2 = find(friends[f2]);

            // 부모 친구의 최댓값 리턴
            cout << max(cnt[p1], cnt[p2]) << '\n';
        }
    }
    return 0;
}
