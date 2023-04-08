// 3190_뱀.cpp
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

const int MAX = 101;

int n, k, l;
int board[MAX][MAX]; // 0: blank, 1: apple, 2: snake
int dy[4] = {0, 1, 0, -1}; // right, down, left, up
int dx[4] = {1, 0, -1, 0};
int cur_dir = 0; // 뱀의 처음 방향 : right
deque<pair<int, int>> snake; // 뱀이 있는 위치

void change_dir(char d){
    if(d == 'L'){ // left
        if(cur_dir == 0) cur_dir = 3;
        else cur_dir -= 1;
    }
    else if(d == 'D'){ // right
        cur_dir = (cur_dir + 1) % 4;
    }
}

bool can_move(){
    pair<int, int> cur_head = snake.front();
    int ny = cur_head.first + dy[cur_dir];
    int nx = cur_head.second + dx[cur_dir];

    // 벽에 부딪치면 false
    if(ny > n || nx > n || ny < 1 || nx < 1) return false;

    // 뱀의 몸과 부딪치면 false
    if(board[ny][nx] == -1) return false;

    // 뱀 머리 이동
    snake.push_front({ny, nx});
    if(board[ny][nx] != 1){ // 사과 없으면 꼬리 이동
        board[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
    }
    board[ny][nx] = -1;
    return true;
}

int main(){
    scanf("%d", &n);
    scanf("%d", &k);

    for(int i = 0; i < k; i++){
        int r, c;
        scanf("%d %d", &r, &c);
        board[r][c] = 1;
    }

    // init
    snake.push_front({1, 1});
    board[1][1] = -1; 
    cur_dir = 0;

    scanf("%d", &l);
    queue<pair<int, char>> q;
    for(int i = 0; i < l; i++){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        q.push({x, c});
    }

    int time = 0;
    while(true){
        // 방향 이동
        if(time == q.front().first){
            change_dir(q.front().second);
            q.pop();
        }
        // 이동 불가능하면 종료
        if(!can_move()) break;
        time++;
    }

    printf("%d\n", time + 1);
    return 0;
}
