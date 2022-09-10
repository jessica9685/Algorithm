// 2022 카카오 인턴십 : 두_큐_합_같게_만들기.cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1, q2;
    long long sum1 = 0;
    long long sum2 = 0;
    for(auto e : queue1){
        q1.push(e);
        sum1 += e;
    }
    for(auto e : queue2){
        q2.push(e);
        sum2 += e;
    }
    
    int answer = -1;
    long long total = sum1 + sum2;
    // 최대 횟수 = 전체 배열의 길이 * 2(왕복)
    int maxCnt = (queue1.size() + queue2.size()) * 2;
    // 전체 합이 짝수여야 두 큐의 합이 같을 수 있음
    if(total % 2 == 0){
        answer = 0;
        while(sum1 != sum2 && answer <= maxCnt){
            if(sum1 > sum2){
                q2.push(q1.front());
                sum1 -= q1.front();
                sum2 += q1.front();
                q1.pop();
            }
            else{
                q1.push(q2.front());
                sum2 -= q2.front();
                sum1 += q2.front();
                q2.pop();
            }
            answer++;
        }
        if(answer > maxCnt) answer = -1;
    }
    return answer;
}
