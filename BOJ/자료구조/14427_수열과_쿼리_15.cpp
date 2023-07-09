// 14427_수열과_쿼리_15.cpp
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define MAX 100001

struct comp{
    bool operator()(const pair<int, int> a, const pair<int, int> b) const{
        if(a.second == b.second){ // 값이 같으면
            // 인덱스 오름차순
            return a.first < b.first;
        }
        // 값의 크기 오름차순
        return a.second < b.second;
    }
};

int n, m;
int arr[MAX];
set<pair<int, int>, comp> pq;

int main() {
    freopen("input.txt", "r", stdin);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        pq.insert({i, arr[i]});
    }
    scanf("%d", &m);

    while(m--){
        int query;
        scanf("%d", &query);

        if(query == 1){
            int i, v;
            scanf("%d %d", &i, &v);

            set<pair<int, int>>::iterator it;
            it = pq.find({i, arr[i]});
            if(it != pq.end()){
                pq.erase(it);
                arr[i] = v;
                pq.insert({i, arr[i]});
            }
        }
        else{
            int ans = pq.begin()->first;
            printf("%d\n", ans);
        }
    }

    return 0;
}
