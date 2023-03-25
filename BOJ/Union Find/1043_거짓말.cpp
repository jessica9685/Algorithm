// 1043_거짓말.cpp
#include <iostream>
#include <vector>
using namespace std;
#define MAX 51

int n, m, k;
vector<int> know_truth;
vector<int> party[MAX];
int parent[MAX];

// 부모 찾기
int find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

// 합치기
void union_set(int a, int b){
    int pa = find(a);
    int pb = find(b);

    parent[pb] = pa;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    
    /* 초기화 */
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) parent[i] = i;

    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int num;
        scanf("%d", &num);
        know_truth.push_back(num);
    }

    /* 같은 파티에 참가하는 인원을 그룹으로 합치기 */
    for(int i = 0; i < m; i++){
        int cnt;
        scanf("%d", &cnt);

        int num, prev;
        for(int j = 0; j < cnt; j++){
            if(j > 0){
                prev = num;
                scanf("%d", &num);
                union_set(prev, num);
            }
            else scanf("%d", &num);
            party[i].push_back(num);
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%d %d\n", i, find(i));
    }

    int ans = m; // 참석 가능한 최대 파티 수
    for(int i = 0; i < m; i++){ // 각 파티의
        bool flag = false;
        for(auto member : party[i]){ // 참여자들 중
            if(flag) break;
            for(auto know : know_truth){ // 진실을 아는 사람과 같은 그룹이면
                if(find(know) == find(member)){
                    flag = true; // 루프 빠져나오고 다음 파티 탐색
                    break;
                }
            }
        }
        if(flag) ans--;
    }

    printf("%d\n", ans);
    return 0;
}
