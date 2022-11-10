// 11593_애너그램_랭킹.cpp
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

string input;
ll alphabet[26];
ll factorial[21];

// 길이가 len인 문자열을 만들 수 있는 경우의 수 구하기
ll permutation(int len){
    ll result = factorial[len];
    for(int i = 0; i < 26; i++){
        if(alphabet[i] > 1) result /= factorial[alphabet[i]];
    }
    return result;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    // 팩토리얼 계산
    factorial[1] = 1;
    for(int i = 2; i <= 20; i++) factorial[i] = factorial[i - 1] * i;

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        // 초기화
        for(int i = 0; i < 26; i++) alphabet[i] = 0;
        cin >> input;

        // 알파벳 개수 구하기
        for(auto ch : input) alphabet[ch - 'A']++;

        int cnt = input.size();
        ll answer = 0;
        for(auto ch : input){
            cnt--;
            // 현재 알파벳보다 순서가 앞인 알파벳들 탐색
            for(int i = 0; i < ch - 'A'; i++){
                if(alphabet[i] == 0) continue;
                alphabet[i]--; // 방문
                answer += permutation(cnt); // 경우의 수 추가
                alphabet[i]++; // 방문 취소
            }
            alphabet[ch - 'A']--;
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
