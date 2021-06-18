// 프로그래머스 : DFS/BFS - 단어_변환.cpp
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    bool pos = false; // words 안에 target이 있으면 true
    for(auto w : words){
        if(w == target) {
            pos = true;
            break;
        }
    }
    // target이 words에 없으면 0    
    if(!pos) return 0;
    
    int answer = 0;
    queue<pair<string, int>> q; // first: word, second: count
    vector<bool> visited(words.size(), false);   
    q.push({begin, 0});
    
    while(!q.empty()){
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        // 현재 단어가 target이면 종료
        if(cur == target){
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < words.size(); i++){
            if(visited[i]) continue;
            
            int diff = 0; // 불일치하는 알파벳 개수
            for(int j = 0; j < cur.size(); j++){
                if(cur[j] != words[i][j]) diff++;
            }
            
            if(diff == 1){ // 한개 빼고 모두 다 같으면
                visited[i] = true;
                q.push({words[i], cnt + 1});
            }
        }
    }
    
    return answer;
}
