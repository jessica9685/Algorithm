// 3020_개똥벌레.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 500001

typedef long long ll;
int n, H;
// 각 높이에 있는 석순/종유석 수
int top[MAX]; // 종유석
int bottom[MAX]; // 석순

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &H);

    // 각 높이에서 끝나는 장애물 수
    for(int i = 0; i < n; i++){
        int h;
        scanf("%d", &h);
        // 석순, 종유석 번갈아가며 등장
        if(i % 2 == 0) bottom[h]++;
        else top[H - h + 1]++;
    }

    // 누적합 계산 => 각 높이에 있는 총 장애물 개수
    // 종유석 : 위로 갈수록 장애물 증가
    for(int i = 1; i <= H; i++){
        top[i] += top[i - 1];
    }

    // 석순 : 아래로 내려갈수록 장애물 증가
    for(int i = H - 1; i >= 0; i--){
        bottom[i] += bottom[i + 1];
    }

    ll ans = 9876543210; // 장애물 최솟값
    int cnt = 0; // 구간의 개수
    for(int i = 1; i <= H; i++){
        if(top[i] + bottom[i] < ans){
            cnt = 1;
            ans = top[i] + bottom[i];
        }
        else if(top[i] + bottom[i] == ans) cnt++;
    }

    printf("%lld %d\n", ans, cnt);
    return 0;
}
