// 1253_좋다.cpp
#include <bits/stdc++.h>
using namespace std;

int n;
int seq[2000];

bool is_good(int idx) {
    int goal = seq[idx]; // 만들고자 하는 수
    int left = 0, right = n - 1; // 투 포인터
    int sum = 0;

    while(left < right){
        sum = seq[left] + seq[right];

        // 수가 일치하면
        if(sum == goal){
            // 본인을 제외한 서로 다른 두 수로 이루어져야 함.
            if(left != idx && right != idx) return true;
            // 본인이 포함되면 포인터 이동
            else if(left == idx) left++;
            else if(right == idx) right--;
        }
        // 목표치보다 작으면 왼쪽 포인터 이동
        else if(sum < goal) left++;
        else right--;
    }
    return false;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &seq[i]);
    
    // 오름차순 정렬
    sort(seq, seq + n);

    int answer = 0;
    // 각 숫자에 대해 이분탐색
    for(int i = 0; i < n; i++){
        if(is_good(i)) answer++;
    }

    printf("%d\n", answer);
    return 0;
}
