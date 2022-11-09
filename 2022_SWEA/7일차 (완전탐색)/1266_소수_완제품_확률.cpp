// 1266_소수_완제품_확률.cpp
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int a, b;
int prime[7] = {2, 3, 5, 7, 11, 13, 17};
ll combi[19];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    // 18Cr 계산
    for(int r = 0; r < 10; r++){
        combi[r] = 1;
        for(int i = 18; i > 18 - r; i--) combi[r] *= i;
        for(int i = 1; i <= r; i++) combi[r] /= i;
        combi[18 - r] = combi[r];
    }

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> a >> b;
        
        double masterA = (double)a / 100;
        double masterB = (double)b / 100;

        double primeA = 0.0, primeB = 0.0;
        for(int i = 0; i < 7; i++){
            double pa = pow(masterA, prime[i]) * pow(1 - masterA, 18 - prime[i]) * (double)combi[prime[i]];
            double pb = pow(masterB, prime[i]) * pow(1 - masterB, 18 - prime[i]) * (double)combi[prime[i]];

            primeA += pa;
            primeB += pb;
        }

        // 1 - (A, B 둘 다 소수 완제품을 만들지 못할 확률)
        double answer = 1.0 - ((1.0 - primeA) * (1.0 - primeB));
        printf("#%d %.6f\n", tc, answer);
    }
    return 0;
}
