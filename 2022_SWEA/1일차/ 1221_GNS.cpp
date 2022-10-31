// 1221_GNS.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 10001

string numStr[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        string testCase;
        int n;
        cin >> testCase >> n;

        int numbers[10] = {0, }; // 각 숫자의 개수
        for(int i = 0; i < n; i++){
            string num;
            cin >> num;
            
            if(num == "ZRO") numbers[0]++;
            else if(num == "ONE") numbers[1]++;
            else if(num == "TWO") numbers[2]++;
            else if(num == "THR") numbers[3]++;
            else if(num == "FOR") numbers[4]++;
            else if(num == "FIV") numbers[5]++;
            else if(num == "SIX") numbers[6]++;
            else if(num == "SVN") numbers[7]++;
            else if(num == "EGT") numbers[8]++;
            else if(num == "NIN") numbers[9]++;
        }

        cout << "#" << tc << "\n";
        for(int i = 0; i < 10; i++){
            for(int cnt = 0; cnt < numbers[i]; cnt++){
                cout << numStr[i] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
