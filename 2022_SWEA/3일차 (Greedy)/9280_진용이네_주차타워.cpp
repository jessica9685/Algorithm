// 9280_진용이네_주차타워.cpp
#include <iostream>
#include <queue>
using namespace std;

int fee[101];
int weight[2001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int n, m;
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            cin >> fee[i];
        }

        for(int i = 1; i <= m; i++){
            cin >> weight[i];
        }

        int isParked[101] = {0, };
        queue<int> q;
        int answer = 0;
        for(int i = 0; i < 2 * m; i++){
            int x;
            cin >> x;
            if(x > 0){ // 들어올 때
                int full = 0;
                for(int i = 1; i <= n; i++){
                    if(isParked[i] == 0){
                        isParked[i] = x;
                        answer += (fee[i] * weight[x]);
                        break;
                    }
                    else full++;
                }
                // 빈 자리가 없으면 큐에 push
                if(full == n) q.push(x);
            }
            else{ // 나갈 때
                x *= -1;
                for(int i = 1; i <= n; i++){
                    if(isParked[i] == x){
                        isParked[i] = 0;
                        if(!q.empty()){
                            isParked[i] = q.front();
                            answer += (fee[i] * weight[isParked[i]]);
                            q.pop();
                        }
                        break;
                    }
                }
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
