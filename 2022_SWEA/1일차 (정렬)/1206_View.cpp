// 1206_View.cpp
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T = 10;
    for(int tc = 1; tc <= T; tc++){
        int n;
        int building[MAX];
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> building[i];
        }

        int answer = 0;
        for(int i = 2; i < n - 2; i++){
            // [i-2] ~ [i+2] 비교
            int maxLen = 0;
            for(int j = i - 2; j <= i + 2; j++){
                if(j == i) continue;
                maxLen = max(maxLen, building[j]);
            }

            if(maxLen > building[i]) continue;
            
            answer += (building[i] - maxLen);
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
