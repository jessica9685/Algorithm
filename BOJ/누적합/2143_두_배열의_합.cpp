// 2143_두_배열의_합.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

typedef long long ll;
ll T;
int m, n;
ll A[MAX], B[MAX];

// 내림차순 정렬
bool comp(ll a, ll b){
    return a > b;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%lld", &T);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &A[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%lld", &B[i]);


    // A 부배열의 합
    vector<ll> subA;
    for(int i = 0; i < n; i++){
        ll sum = A[i];
        subA.push_back(A[i]);
        for(int j = i + 1; j < n; j++){
            sum += A[j];
            subA.push_back(sum);
        }
    }

    // B 부배열의 합
    vector<ll> subB;
    for(int i = 0; i < m; i++){
        ll sum = B[i];
        subB.push_back(B[i]);
        for(int j = i + 1; j < m; j++){
            sum += B[j];
            subB.push_back(sum);
        }
    }

    sort(subA.begin(), subA.end()); // subA 오름차순 정렬
    sort(subB.begin(), subB.end(), comp); // subB 내림차순 정렬

    int pa = 0; // subA의 포인터
    int pb = 0; // subB의 포인터
    ll cnt = 0; // 경우의 수

    while(pa < subA.size() && pb < subB.size()){
        ll curA = subA[pa];
        ll curB = subB[pb];
        ll goalB = T - curA;

        if(curB > goalB) pb++;
        else if(curB == goalB){ // 목표 숫자를 만든 경우
            // 중복 숫자 개수 세기
            ll cntA = 0, cntB = 0;
            while(pa < subA.size() && subA[pa] == curA){
                pa++;
                cntA++;
            }
            while(pb < subB.size() && subB[pb] == curB){
                pb++;
                cntB++;
            }
            cnt += (cntA * cntB);
        }
        else pa++;
    }

    printf("%lld\n", cnt);
    return 0;
}
