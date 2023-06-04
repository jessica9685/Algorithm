// 5568_카드_놓기.cpp
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, k;
int card[10];
unordered_set<int> nums;
int selected[10];

void dfs(int idx, int cnt) {
    if (cnt == k) {
        do {
            string str;
            for (int i = 0; i < k; i++) {
                str += to_string(selected[i]);
            }
            nums.insert(stoi(str));
        } while(next_permutation(selected, selected + k));
        
        return;
    }

    for (int i = idx; i < n; i++) {
        selected[cnt] = card[i];
        dfs(i + 1, cnt + 1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }

    sort(card, card + n);
    dfs(0, 0);
    
    int ans = nums.size();
    printf("%d\n", ans);
    return 0;
}
