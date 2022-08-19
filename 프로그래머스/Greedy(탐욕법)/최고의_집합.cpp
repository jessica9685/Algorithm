// 연숩문제 : 최고의_집합.cpp
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int N = n; // 개수 따로 저장
    
    // 곱의 최댓값: (s/n)으로 이루어진 수들
    while(n > 0){
        int num = s / n;
        if(num == 0) {
            num = s % n; // 몫이 0이면 나머지를 push
            if(num == 0) break; // 0이면 종료
        }
        answer.push_back(num);
        n--;
        s -= num;
    }
    
    // 집합의 원소 개수가 n보다 작으면 -1
    if(answer.size() < N) {
        answer.clear();
        answer.push_back(-1);
    }
    
    return answer;
}
