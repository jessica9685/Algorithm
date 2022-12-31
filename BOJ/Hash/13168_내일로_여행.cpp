// 13168_내일로_여행.cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define MAX 100
#define INF 1e9

int n, r, m, k;
string name;
map<string, int> cities; // string으로 된 도시 이름을 int로 매핑
vector<int> plan; // 여행갈 도시

double no_railro[MAX][MAX]; // 내일로 티켓 안샀을 때 비용
double railro[MAX][MAX]; // 내일로 티켓 샀을 때 비용

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    // 전체 도시
    cin >> n >> r;
    for(int i = 0; i < n; i++){
        cin >> name;
        cities[name] = i;
    }

    // dist init
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            no_railro[i][j] = INF;
            railro[i][j] = INF;
        }
    }

    // 여행갈 도시
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> name;
        plan.push_back(cities[name]);
    }

    // 교통수단
    cin >> k;
    for(int i = 0; i < k; i++){
        string type, s, e;
        double cost;
        cin >> type >> s >> e >> cost;

        int start = cities[s];
        int end = cities[e];

        no_railro[start][end] = min(no_railro[start][end], cost);
        no_railro[end][start] = min(no_railro[end][start], cost);

        // 무료
        if(type == "Mugunghwa" || type == "ITX-Cheongchun" || type == "ITX-Saemaeul"){
            railro[start][end] = 0;
            railro[end][start] = 0;
        }
        // 50% 할인
        else if(type == "S-Train" || type == "V-Train"){
            railro[start][end] = min(railro[start][end], cost / 2);
            railro[end][start] = min(railro[end][start], cost / 2);
        }
        // 그대로
        else{
            railro[start][end] = min(railro[start][end], cost);
            railro[end][start] = min(railro[end][start], cost);
        }
    }

    // Floyd
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                no_railro[i][j] = min(no_railro[i][j], no_railro[i][k] + no_railro[k][j]);
                railro[i][j] = min(railro[i][j], railro[i][k] + railro[k][j]);
            }
        }
    }

    // 가격 비교
    double discount = 0;
    double no_discount = 0;
    for(int i = 0; i < m - 1; i++){
        int start = plan[i];
        int end = plan[i + 1];

        discount += railro[start][end];
        no_discount += no_railro[start][end];
    }

    if(discount + r < no_discount) printf("Yes\n");
    else printf("No\n"); 
    return 0;
}
