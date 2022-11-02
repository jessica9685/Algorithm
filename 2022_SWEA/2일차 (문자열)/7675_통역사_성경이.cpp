// 7675_통역사_성경이.cpp
#include <iostream>
#include <string>
using namespace std;

bool isName(string name){
    if(!(name[0] >= 'A' && name[0] <= 'Z')) return false;
    else{
        // 1글자인 경우
        if(name.size() == 1) return true;

        // 2글자 이상인 경우
        bool flag = true;
        for(int i = 1; i < name.size(); i++){
            if(!(name[i] >= 'a' && name[i] <= 'z')){
                flag = false;
                break;
            }
        }
        return flag;
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int n; // 문장의 개수
        cin >> n; 

        int answer[5] = {0, };
        for(int i = 0; i < n; i++){
            while(true){
                string str;
                cin >> str;
                int len = str.size();

                if(str[len - 1] == '.' || str[len - 1] == '!' || str[len - 1] == '?'){
                    str = str.substr(0, len - 1);
                    if(isName(str)) answer[i]++;
                    break;
                }
                else if(isName(str)) answer[i]++;
            }
        }

        cout << "#" << tc << " ";
        for(int i = 0; i < n; i++) cout << answer[i] << " ";
        cout << "\n";
    }
    return 0;
}
