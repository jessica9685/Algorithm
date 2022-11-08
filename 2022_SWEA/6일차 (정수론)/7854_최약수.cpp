// 7854_최약수.cpp
#include <iostream>
using namespace std;

int num_len(int num){
    int cnt = 0;
    while(num > 0){
        num /= 10;
        cnt++;
    }
    return cnt;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int x;
        cin >> x;

        int cnt = 0;
        // 1, 2, 5
        if(x < 2) cnt = 1;
        else if(x >= 2 && x < 5) cnt = 2;
        else if(x >= 5 && x < 10) cnt = 3;
        // 10, 20, 25, 50
        else if(x >= 10 && x < 20) cnt = 4;
        else if(x >= 20 && x < 25) cnt = 5;
        else if(x >= 25 && x < 50) cnt = 6;
        else if(x >= 50 && x < 100) cnt = 7;
        /* 
            100, 125, 200, 250, 500
            1000, 1250, 2000, 2500, 5000
            ...
        */
        else{
            int len = num_len(x);
            cnt = 8 + ((len - 3) * 5);

            while(x >= 1000) x /= 10;

            if(x >= 500) cnt += 4;
            else if(x >= 250 && x < 500) cnt += 3;
            else if(x >= 200 && x < 250) cnt += 2;
            else if(x >= 125 && x < 200) cnt += 1;
        }

        cout << "#" << tc << " " << cnt << "\n";
    }
    return 0;
}
