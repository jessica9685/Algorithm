// 프로그래머스 : 월간 코드 챌린지 시즌1 - 풍선_터트리기.cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int s = a.size();
    if(s < 3) answer = s;
    else{
        // 현재 값 기준으로 우측 최솟값 (양 끝 제외) (자기자신 포함)
        vector<int> right = a;
        for(int i = s - 2; i > 0; i--){
            right[i] = min(right[i], right[i + 1]);
        }
        
        answer = 2; // 양 끝은 무조건 가능
        int left = a[0]; // 현재 값 기준으로 좌측 최솟값
        for(int i = 1; i < s - 1; i++){
            // 좌, 우 최솟값 둘 다 현재값보다 크면 안됨
            if(!(a[i] > left && a[i] > right[i + 1])) answer++;
            // 좌측 최솟값 갱신
            left = min(left, a[i]);
        }
    }
    
    return answer;
}
