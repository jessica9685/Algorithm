// 1213_String.cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T = 10;
    while(T--){
        int tc;
        cin >> tc;

        string search, str;
        cin >> search; // 찾는 문자열
        cin >> str; // 전체 문자열

        int answer = 0;
        int len = search.size();
        for(int i = 0; i <= str.size() - len; i++){
            string temp = str.substr(i, len);
            if(temp == search) answer++;
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
