// 9480_민정이와_광직이의_알파벳_공부.cpp
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, answer;
int words[15];
const int AL_CHECK = (1 << 26) - 1;

void dfs(int idx, int mark){
    if(idx == n) {
        if(mark == AL_CHECK) answer++;
        return;
    }

    // idx번째 단어 포함
    dfs(idx + 1, mark | words[idx]);
    // idx번째 단어 포함 X
    dfs(idx + 1, mark);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> n;
        for(int i = 0; i < n; i++){
            string word;
            cin >> word;

            // 단어에 포함된 알파벳 마킹
            words[i] = 0;
            for(auto ch : word) words[i] |= (1 << (ch - 'a'));
        }

        answer = 0;
        dfs(0, 0);
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
