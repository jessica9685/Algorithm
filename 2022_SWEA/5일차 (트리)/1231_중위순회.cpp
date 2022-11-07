// 1231_중위순회.cpp
#include <iostream>
using namespace std;
#define MAX 101

typedef struct Node{
    int num;
    char ch;
    int left, right;
} Node;

int n;
Node tree[MAX];

void insert(int num, char ch, int left, int right){
    tree[num].ch = ch;
    tree[num].left = left;
    tree[num].right = right;
}

void inorder(Node cur){
    if(cur.left != -1) inorder(tree[cur.left]);
    cout << cur.ch;
    if(cur.right != -1) inorder(tree[cur.right]);
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int T = 10;
    for(int tc = 1; tc <= T; tc++){
        cin >> n;

        for(int i = 1; i <= n; i++){
            int num, left, right;
            char ch;
            cin >> num >> ch;

            if(n % 2 == 0){ // 노드 개수가 짝수
                if(n / 2 == num){ // left만 존재
                    cin >> left;
                    insert(num, ch, left, -1);
                }
                else if(n / 2 > num){ // left, right 존재
                    cin >> left >> right;
                    insert(num, ch, left, right);
                }
                else { // 리프노드
                    insert(num, ch, -1, -1);
                }
            }
            else{ // 노드 개수가 홀수
                if(n / 2 >= num){ // left, right 존재
                    cin >> left >> right;
                    insert(num, ch, left, right);
                }
                else{ // 리프노드
                    insert(num, ch, -1, -1);
                }
            }
        }

        cout << "#" << tc << " ";
        inorder(tree[1]);
        cout << "\n";
    }
    return 0;
}
