// 8898_3차원_농부.cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define INF 999999999
#define MAX 500000

int n, m, c1, c2;
int cow[MAX];

// cow에서 horse[i](value)와 가장 근접하게 큰 값의 index 찾기
// 이분탐색
int binarySearch(int value){
    int left = 0, right = n - 1;

    if(cow[left] > value) return left;
    if(cow[right] < value) return right;
    
    int mid = 0;
    while(left <= right){
        mid = (left + right) / 2;

        if(cow[mid] == value) return mid;
        else if(cow[mid] < value) left = mid + 1;
        else right = mid - 1;
    }

    if(cow[mid] < value) mid++;

    return mid;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> n >> m;    
        cin >> c1 >> c2;
        int xdist = abs(c1 - c2);

        for(int i = 0; i < n; i++) cin >> cow[i];
        sort(cow, cow + n); // 오름차순 정렬
        
        int minDist = INF;
        int minCnt = 0;
        for(int i = 0; i < m; i++) {
            int horse;
            cin >> horse;

            for(int d = -1; d < 1; d++){
                int z = binarySearch(horse);
                z += d;

                if(z < 0 || z >= n) continue;

                int dist = abs(cow[z] - horse);
                if(minDist > dist){
                    minDist = dist;
                    minCnt = 1;
                }
                else if(minDist == dist) minCnt++;
            }
        }
        cout << "#" << tc << " " << minDist + xdist << " " << minCnt << "\n";
    }
    return 0;
}
