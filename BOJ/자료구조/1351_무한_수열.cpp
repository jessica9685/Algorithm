// 1351_무한_수열.cpp
#include <iostream>
#include <map>
using namespace std;

/*
    map과 unordered_map의 차이
    map: key값 기준으로 이진탐색트리 구조로 sorting. O(logN)
    unordered_map: sorting이 따로 되어있지 않는 hash table 구조. O(1)
    -> unordered_map이 더 빠르긴 하지만, key가 유사한 데이터가 많을수록 해시 충돌로 인해 성능 저하
    -> index로 접근 불가. iterator로만 접근 가능
*/

// p, q의 범위: ~10^19
typedef long long ll;
ll N, P, Q;
map<ll, ll> seq;

ll func(ll i){
    // A[0] = 1
    if(i == 0) return 1;

    // A[i]의 값이 이미 존재하면 그대로 리턴
    if(seq.count(i)) return seq[i];
    // 없으면 계산
    else return seq[i] = func(i / P) + func(i / Q);
}

int main(){
    scanf("%lld %lld %lld", &N, &P, &Q);

    ll answer = func(N);
    printf("%lld\n", answer);
    return 0;
}
