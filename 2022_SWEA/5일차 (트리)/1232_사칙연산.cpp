// 1232_사칙연산.cpp
#include <iostream>
#include <string>
using namespace std;
#define MAX 1001

typedef struct Node{
    bool isNum;
    int num;
    string op;
    int left, right;
} Node;

int n;
Node tree[MAX];

void insert(int idx, string op, bool isNum, int left, int right){
    tree[idx].isNum = isNum;
    if(isNum){
        int num = 0;
        for(int i = 0; i < op.size(); i++){
            num += (op[i] - '0');
            num *= 10;
        }
        tree[idx].num = num / 10;
    }
    else tree[idx].op = op;
    
    tree[idx].left = left;
    tree[idx].right = right;
}

double postorder(Node cur){
    if(cur.isNum) return cur.num;
    else{
        double a = postorder(tree[cur.left]);
        double b = postorder(tree[cur.right]);
        if(cur.op == "+") return a + b;
        else if(cur.op == "-") return a - b;
        else if(cur.op == "*") return a * b;
        else if(cur.op == "/") return a / b;
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int T = 10;
    for(int tc = 1; tc <= T; tc++){
        cin >> n;

        for(int i = 1; i <= n; i++){
            int idx;
            string op;
            cin >> idx >> op;

            if(op == "+" || op == "-" || op == "/" || op == "*"){
                int left, right;
                cin >> left >> right;
                insert(idx, op, false, left, right);
            }
            else insert(idx, op, true, -1, -1);
        }
        
        int answer = postorder(tree[1]);
        cout << "#" << tc << " " << answer << "\n";

    }
    return 0;
}
