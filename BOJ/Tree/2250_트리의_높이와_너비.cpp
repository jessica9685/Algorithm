// 2250_트리의_높이와_너비.cpp
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
#define INF 10010

int n, col; // col: 노드가 위치한 열 번호
// 노드 입력 횟수 (root node를 찾기 위함)
int node_cnt[MAX]; 
pair<int, int> tree[MAX]; // first: left, second: right
// 각 레벨에서의 가장 높은/낮은 열 번호
int low[MAX], high[MAX];

// 중위 순회
void inorder(int node, int level){
    // left 탐색
    if(tree[node].first != -1) inorder(tree[node].first, level + 1);

    // visit
    low[level] = min(low[level], col);
    high[level] = max(high[level], col++);

    // right 탐색
    if(tree[node].second != -1) inorder(tree[node].second, level + 1);
}

int main(){
    // 초기화
    for(int i = 0; i < MAX; i++){
        low[i] = INF;
        high[i] = 0;
    }

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int node, left, right;
        scanf("%d %d %d", &node, &left, &right);
        
        node_cnt[node]++;
        if(left != -1) node_cnt[left]++;
        if(right != -1) node_cnt[right]++;
        tree[node].first = left;
        tree[node].second = right;
    }

    // 루트 찾기
    int root;
    for(int i = 1; i <= n; i++){
        if(node_cnt[i] == 1) { // 1번만 입력받은 노드가 루트
            root = i;
            break;
        }
    }

    // 중위 순회
    col = 1;
    inorder(root, 1);

    // 최대 너비 & 레벨 구하기
    int level = 1;
    int maxLen = high[1] - low[1] + 1;
    for(int i = 2; i <= n; i++){
        int len = high[i] - low[i] + 1;
        if(len > maxLen){
            maxLen = len;
            level = i;
        }
    }

    printf("%d %d\n", level, maxLen);
    return 0;
}
