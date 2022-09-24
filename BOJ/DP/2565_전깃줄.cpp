// 2565_전깃줄.cpp
#include <bits/stdc++.h>
using namespace std;

int n; // 전깃줄 개수
vector<pair<int, int>> lines;
// 교차하지 않는 전깃줄 최대 개수
// == 가장 긴 증가하는 부분 수열
int dp[101] = {0, };

int main()
{
    scanf("%d", &n);

    lines.push_back({0, 0}); // index 1부터 시작하기 위함
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        lines.push_back({a, b});
    }
    // A 기준 오름차순 정렬
    sort(lines.begin(), lines.end());

    int remain = 0; // 남길 전깃줄 개수
    // B에서 가장 긴 증가하는 부분수열 구하기
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(lines[j].second < lines[i].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        remain = max(remain, dp[i]);
    }
    
    printf("%d\n", n - remain);
    return 0;
}
