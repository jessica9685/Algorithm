// 7854_최약수.cpp
#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        ll x;
        cin >> x;

        int cnt = 0;
        ll limit = x * 10;
        for(ll i = 1; i <= limit; i *= 10){
            // 10의 배수는 최약수
            if(i <= x) cnt++;

            // 10의 배수의 약수도 최약수
            // 2, 5, 20, 25, 125, 250, 500...
            for(ll j = 2; j <= 9; j++){
                if((i % j == 0) && (i / j <= x)) cnt++;
            }
        }

        cout << "#" << tc << " " << cnt << "\n";
    }
    return 0;
}
