// 프로그래머스 : 해시(Hash) - 베스트앨범.cpp
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

// 장르별 횟수 내림차순 정렬
bool genre_compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

// 장르 내 노래별 횟수 내림차순 정렬
struct play_compare{
    bool operator()(tuple<int, string, int> a, tuple<int, string, int> b){
        // 장르 내에서 재생 횟수가 같으면
        if(get<0>(a) == get<0>(b)){
            // 고유번호가 낮은 순서대로 정렬
            return get<2>(a) > get<2>(b);
        }
        // 재생 횟수가 많은 순서대로 정렬
        else return get<0>(a) < get<0>(b);
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> hash_map;
    // 0: play 횟수, 1: 장르, 2: 고유번호
    vector<tuple<int, string, int>> music;
    for(int i = 0; i < genres.size(); i++){
        hash_map[genres[i]] += plays[i];
        music.push_back({plays[i], genres[i], i});
    }
    
    // 가장 많이 재생된 장르 순으로 정렬
    vector<pair<string, int>> vec(hash_map.begin(), hash_map.end());
    sort(vec.begin(), vec.end(), genre_compare);
    
    // 많이 재생된 장르 순서대로 순회
    for(int i = 0; i < vec.size(); i++){
        string g = vec[i].first;
        
        priority_queue<tuple<int, string, int>, vector<tuple<int, string, int>>, play_compare> pq;
        for(auto m : music){
            if(get<1>(m).compare(g) == 0){
                pq.push(m);
            }
        }
        
        // 첫 번째로 많이 재생된 노래
        int a = get<2>(pq.top());
        pq.pop();
        answer.push_back(a);
        
        // 두 번째로 많이 재생된 노래
        if(!pq.empty()) { 
            int b = get<2>(pq.top());
            answer.push_back(b);
        }
    }
    
    return answer;
}
