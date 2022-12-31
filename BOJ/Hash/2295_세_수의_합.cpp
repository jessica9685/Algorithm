// 2295_세_수의_합.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001

int n;
int seq[MAX];
vector<int> sum2; // 두 수의 합

bool binarySearch(int num){
    int left = 0;
    int right = sum2.size() - 1;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;
        if(sum2[mid] == num) return true;
        else if(num < sum2[mid]) right = mid - 1;
        else left = mid + 1;
    }

    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &seq[i]);
    sort(seq, seq + n); // 오름차순 정렬
    
    // a + b + c = d (a, b, c, d 중복 가능)
    // a + b = d - c
    // a + b의 값을 저장
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++) {
            sum2.push_back(seq[i] + seq[j]);
        }
    }
    sort(sum2.begin(), sum2.end()); // 오름차순 정렬

    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(binarySearch(seq[j] - seq[i])){
                answer = max(answer, seq[j]);
            }
        }
    }

    printf("%d\n", answer);
    return 0;
}
