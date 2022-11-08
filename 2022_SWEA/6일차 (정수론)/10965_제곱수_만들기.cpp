// 10965_제곱수_만들기.cpp
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define MAX 10000001

bool isPrime[MAX]; // 소수가 아니면 true
vector<int> prime;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    // A의 최댓값까지 소수 판별
    for(int i = 2; i <= (int)sqrt(MAX) + 1; i++){
        if(isPrime[i]) continue;
        else prime.push_back(i);
        for(int j = i * 2; j < MAX; j += i) isPrime[j] = true;
    }

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int num;
        cin >> num;

        // 1이거나 소수인 경우 
        if(!isPrime[num] || num == 1){
            cout << "#" << tc << " " << num << "\n";
            continue;
        }
        
        // 소인수분해
        int square = prime[0] * prime[0];
        int idx = 0;
        while(square <= num){
            if(num % square == 0) num /= square;
            else{
                idx++;
                square = prime[idx] * prime[idx];
            }
        }
        cout << "#" << tc << " " << num << "\n";
    }
    return 0;
}
