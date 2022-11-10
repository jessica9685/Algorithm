// 9480_민정이와_광직이의_알파벳_공부.cpp
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<string> words;
bool visited[15];
int answer;

void dfs(int idx, int cnt){
    if(cnt == 0){
        bool alphabet[26] = {false, };
        for(int i = 0; i < n; i++){
            if(!visited[i]) continue;
            for(auto ch : words[i]){
                if(!alphabet[ch - 'a']) alphabet[ch - 'a'] = true;
            }
        }
        for(int i = 0; i < 26; i++){
            if(!alphabet[i]) return;
        }
        answer++;
    }

    for(int i = idx; i < n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i + 1, cnt - 1);
        visited[i] = false;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> n;
        // 초기화
        words.clear();
        for(int i = 0; i < n; i++) visited[i] = false;
        answer = 0;

        for(int i = 0; i < n; i++){
            string word;
            cin >> word;
            words.push_back(word);
        }

        for(int cnt = 1; cnt <= n; cnt++) dfs(0, cnt);

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
