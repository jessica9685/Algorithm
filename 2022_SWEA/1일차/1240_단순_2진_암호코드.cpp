// 1240_단순_2진_암호코드.cpp
#include <iostream>
#include <string>
using namespace std;
#define MAX 1001

string numCode[10] = {
    "0001101",
    "0011001",
    "0010011",
    "0111101",
    "0100011",
    "0110001",
    "0101111",
    "0111011",
    "0110111",
    "0001011"
};

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int n, m;
        cin >> n >> m;

        string newCode;
        for(int i = 0; i < n; i++){
            string scanner;
            cin >> scanner;

            // 0만 있으면 다음꺼 탐색
            if(scanner.find('1') == -1) continue;

            // 맨 뒤에서부터 1을 탐색 (모든 암호코드는 1로 끝남)
            // newCode = scanner.substr(scanner.rfind('1') - 55, 56);
            for(int pos = scanner.size() - 1; pos >= 55; pos--){
                if(scanner[pos] == '1'){
                    newCode = scanner.substr(pos - 55, 56);
                    break;
                }
            }
        }

        int odd = 0, even = 0;
        for(int k = 0; k < 8; k++){
            string code = newCode.substr(7 * k, 7);
                
            for(int num = 0; num < 10; num++){
                if(code == numCode[num]){
                    if(k % 2 == 0) odd += num;
                    else even += num;
                    break;
                }
            }
        }
        
        int check = (odd * 3) + even;
        int answer = 0;
        if(check % 10 == 0) answer = odd + even;
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
