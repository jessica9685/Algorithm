// 연습문제 : 최솟값_만들기.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end()); // 오름차순
    sort(B.begin(), B.end(), comp); // 내림차순
    
    int answer = 0;
    for(int i = 0; i < A.size(); i++){
        answer += (A[i] * B[i]);
    }    
    return answer;
}
