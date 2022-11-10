// 14179_복제한_수열의_인버전_수.cpp
#include <iostream>
using namespace std;
 
typedef long long ll;

int n;
ll k;
int seq[2001];
const ll MOD = 1000000007;
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
 
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> n >> k;
 
        for(int i = 0; i < n; i++) {
            cin >> seq[i];
        }
 
        // seq[i] > seq[j] 인 j의 개수
        ll inv[2001] = {0, }; // i < j
        ll inv_rev[2001] = {0, }; // i > j
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(seq[i] > seq[j]) inv[i]++;
            }
            for(int j = 0; j < i; j++){
                if(seq[i] > seq[j]) inv_rev[i]++;
            }
        }
 
        ll answer = 0;
        ll sum_inv = 0, sum_inv_rev = 0;
        for(int i = 0; i < n; i++) {
            sum_inv += inv[i];
            sum_inv_rev += inv_rev[i];
        }
        if(k == 1) answer = sum_inv % MOD;
        else {
            ll combi = k * (k - 1) / 2 % MOD;
            answer += ((sum_inv) * k) % MOD;
            answer += ((sum_inv_rev + sum_inv) * combi) % MOD;
            answer %= MOD;
        }
 
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
