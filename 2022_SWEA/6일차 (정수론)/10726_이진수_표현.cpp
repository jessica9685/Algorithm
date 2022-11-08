// 10726_이진수_표현.cpp
#include <iostream>
#include <cmath>
using namespace std;

int n, m;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> n >> m;
        string answer = "ON";

        for(int i = 0; i < n; i++){
            if((m & (1 << i)) != (1 << i)) {
                answer = "OFF";
                break;
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
