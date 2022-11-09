// 10965_제곱수_만들기.cpp
#include <iostream>
using namespace std;
#define MAX 10000001

int minNum[MAX];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    for(int i = 1; i < MAX; i++){
        minNum[i] = i;
    }

    for(int i = 2; i * i < MAX; i++){
        // 이미 갱신됐으면 패스
        if(minNum[i * i] < i * i) continue;
        // 제곱수로 나눠지면 나누기
        for(int j = i * i; j < MAX; j += (i * i)){
            while(minNum[j] % (i * i) == 0){
                minNum[j] /= (i * i);
            }
        }
    }

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int x;
        cin >> x;
        
        cout << "#" << tc << " " << minNum[x] << "\n";
    }
    return 0;
}
