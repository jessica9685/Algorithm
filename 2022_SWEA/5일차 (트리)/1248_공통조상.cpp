// 1248_공통조상.cpp
#include <iostream>
using namespace std;
#define MAX 10001

int v, e, a, b;

typedef struct Node{
    int parent;
    int left, right;
} Node;

Node tree[MAX];

void init(int n){
    for(int i = 1; i <= n; i++){
        tree[i].parent = 1;
        tree[i].left = -1;
        tree[i].right = -1;
    }
}

int find_equal_parent(int x, int y) {
    bool visited[MAX] = {false, };
    // x의 부모 찾기
    while(x != 1){
        x = tree[x].parent;
        visited[x] = true;
    }

    while(y != 1){
        y = tree[y].parent;
        if(visited[y]) return y;
    }

    return 1;
}

int count_node(Node cur){
    int left = 0, right = 0;
    if(cur.left != -1) left = count_node(tree[cur.left]);
    if(cur.right != -1) right = count_node(tree[cur.right]);
    return left + right + 1;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> v >> e >> a >> b;
        init(v);

        for(int i = 0; i < e; i++){
            int parent, child;
            cin >> parent >> child;

            if(tree[parent].left == -1) tree[parent].left = child;
            else tree[parent].right = child;
            
            tree[child].parent = parent;
        }

        int p = find_equal_parent(a, b);
        int cnt = count_node(tree[p]);
        cout << "#" << tc << " " << p << " " << cnt << "\n";
    }
    return 0;
}
