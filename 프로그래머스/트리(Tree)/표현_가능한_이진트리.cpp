// 2023 카카오 : 표현_가능한_이진트리.cpp
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string dec_to_binary(long long num){
    string bin = "";
    
    // 2진수로 만들기
    while(num > 0){
        long long mod = num % 2;
        bin += ('0' + mod);
        num /= 2;
    }
    
    reverse(bin.begin(), bin.end());
    
    // 포화 이진 트리의 형태로 만들기
    int level = 1; // 트리 레벨
    while(true){
        if(bin.size() <= pow(2, level) - 1) break;
        else level++;
    }
    
    int add_zero = (int)pow(2, level) - 1 - bin.size();
    while(add_zero--) bin = "0" + bin;
    
    return bin;
}

bool is_possible_binary_tree(string binary){
    if(binary.size() == 1) return true;
    
    int mid = binary.size() / 2;
    
    string left = binary.substr(0, mid);
    string right = binary.substr(mid + 1);
    
    char root = binary[mid];
    char left_root = left[left.size() / 2];
    char right_root = right[right.size() / 2];
    
    if(is_possible_binary_tree(left) && is_possible_binary_tree(right)){
        // 루트가 1인 경우
        if(root == '1') return true;
        
        // 루트가 0인 경우
        if(left_root == '0' && right_root == '0') return true;
    }
    return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(auto num : numbers){
        string bin = dec_to_binary(num);
        
        if(is_possible_binary_tree(bin)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}
