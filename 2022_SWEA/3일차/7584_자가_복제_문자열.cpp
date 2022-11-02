// 7584_자가_복제_문자열.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        ll k;
        cin >> k;
        k--;

        // 패턴 찾기
        /*
            P3 = 0 0 1 0 0 1 1 0 0 0 1 1 0 1 1 
            1인 index: 2, 5, 6, 10, 11, 13, 14
            0인 index: 0, 1, 3, 4, 7, 8, 9, 12
            => 4의 배수 index는 0
            => 4의 배수가 아닌 2의 배수 index는 1
            => 홀수면 값이 짝수가 나올 때까지 / 2
        */

        int answer = 0;
        while(k >= 0){
            // k가 홀수이면
            if(k % 2 == 1){
                k /= 2;
            }
            // k가 4의 배수이면 0
            if(k % 4 == 0){
                answer = 0;
                break;
            }
            // 4의 배수가 아닌 2의 배수이면 1
            else if(k % 2 == 0){
                answer = 1;
                break;
            }
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
