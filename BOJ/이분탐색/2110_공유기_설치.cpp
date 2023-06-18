// 2110_공유기_설치.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, c;
vector<ll> house;

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &c);

    for(int i = 0; i < n; i++){
        ll x;
        scanf("%lld", &x);
        house.push_back(x);
    }

    sort(house.begin(), house.end());

    ll left = 0; // 1번째 공유기 ~ 1번째 공유기 사이 간격
    ll right = house[n - 1] - house[0]; // 1번째 공유기 ~ 마지막 공유기 사이 간격
    ll ans = 0; // 가장 인접한 간격 최댓값

    while(left <= right){
        // 첫 번째 집에는 무조건 공유기 설치
        ll start = house[0];
        int cnt = 1; // 설치한 공유기 개수
        
        ll mid = (left + right) / 2; // 기준 간격

        for(int i = 1; i < n; i++){
            ll end = house[i];

            if(end - start >= mid){
                cnt++;
                start = end;
            }
        }

        // 설치된 공유기 개수가 c개 이상이면 
        if(cnt >= c){
            ans = max(ans, mid); // ans 갱신
            left = mid + 1;
        }
        else right = mid - 1;
    }

    printf("%d\n", ans);
    return 0;
}
