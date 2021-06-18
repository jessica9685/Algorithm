// 프로그래머스 : DFS/BFS - 타겟_넘버.cpp
#include <string>
#include <vector>

using namespace std;

int answer = 0;

// cnt : 인덱스
void dfs(vector<int> numbers, int target, int sum, int cnt){
    if(cnt == numbers.size() - 1){
        if(target == sum + numbers[cnt]) answer++;
        if(target == sum - numbers[cnt]) answer++;
        return;
    }
    
    dfs(numbers, target, sum + numbers[cnt], cnt + 1);
    dfs(numbers, target, sum - numbers[cnt], cnt + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}
