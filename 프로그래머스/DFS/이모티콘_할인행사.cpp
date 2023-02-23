// 2023 카카오 : 이모티콘_할인행사.cpp
#include <string>
#include <vector>
using namespace std;

int discount[4] = {10, 20, 30, 40};
int max_customer = 0;
int max_price = 0;

void dfs(vector<int> &emo_combi, vector<vector<int>> &users, vector<int> &emoticons){
    if(emo_combi.size() == emoticons.size()){ // 조합이 완성되면
        int customers = 0;
        int benefits = 0;
        
        // 각 고객의 이모티콘 구매 비용 & 가입 여부 구하기
        for(int u = 0; u < users.size(); u++){
            int price = 0;
            for(int i = 0; i < emoticons.size(); i++){
                if(emo_combi[i] >= users[u][0]){
                    price += emoticons[i] * (100 - emo_combi[i]) / 100;
                }
            }
            if(price >= users[u][1]) customers++;
            else benefits += price;
        }
        
        if(customers > max_customer){
            max_customer = customers;
            max_price = benefits;
        }
        else if(customers == max_customer && max_price < benefits){
            max_price = benefits;
        }
        return;
    }
    
    // 각 이모티콘 할인율 중복조합 찾기
    for(int i = 0; i < 4; i++){
        emo_combi.push_back(discount[i]);
        dfs(emo_combi, users, emoticons);
        emo_combi.pop_back();
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> emo_combi;
    
    dfs(emo_combi, users, emoticons);
    
    vector<int> answer;
    answer.push_back(max_customer);
    answer.push_back(max_price);
    return answer;
}
