// 2749_피보나치_수_3.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000

typedef long long ll;

ll n;
// 피사노 주기 (피보나치 수를 임의의 수 K로 나눌 때의 나머지는 항상 주기를 가짐)
// 주기(P) = 15 * 10^(k - 1) (M = 10 ^ k일 때 (k > 2))
const int cycle = 15 * (MOD / 10);
int fibo[cycle];

int main() {
    freopen("input.txt", "r", stdin);
    
    scanf("%lld", &n);

    if(n == 0) printf("0\n");
    else if(n == 1) printf("1\n");
    else{
        fibo[0] = 0;
        fibo[1] = 1;

        for(int i = 2; i < cycle; i++){
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
        }

        printf("%d\n", fibo[n % cycle]);
    }

    return 0;
}
