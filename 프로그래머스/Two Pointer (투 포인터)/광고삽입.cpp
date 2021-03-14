// 2021 카카오 : 광고삽입.cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 문자열 -> 시간(초)
int strToSec(string time){
    int hour = stoi(time.substr(0, 2)) * 60 * 60;
    int min = stoi(time.substr(3, 2)) * 60;
    int sec = stoi(time.substr(6, 2));
    
    return hour + min + sec;
}

// 시간(초) -> 문자열
string secToStr(int time){
    string str = "";
    
    int sec = time % 60;
    time /= 60;
    int min = time % 60;
    time /= 60;
    int hour = time;
    
    if(hour < 10) str += "0";
    str += to_string(hour);
    str += ":";
    
    if(min < 10) str += "0";
    str += to_string(min);
    str += ":";
    
    if(sec < 10) str += "0";
    str += to_string(sec);
    
    return str;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    // 지역변수로 선언 시 반드시 0으로 초기화해주기
    // 전역변수로 선언할 때는 자동으로 0으로 초기화되지만,
    // 지역변수로 선언할 때는 내가 명시해줘야함
    int timeline[360000] = { 0, }; // 각 시간별 누적 시청자 수
    
    
    int n = strToSec(play_time); // 전체 길이
    int m = strToSec(adv_time); // 광고 길이
    
    for(string log : logs){
        int start = strToSec(log.substr(0, 8));
        int end = strToSec(log.substr(9, 8));
        
        // 각 시간별 시청자 수 누적
        for(int i = start; i < end; i++) timeline[i]++;
    }
    
    queue<int> q; // 길이 m인 구간의 원소
    // sum 초기화 (맨 처음부터 길이 m까지의 누적 시청자 수)
    long long sum = 0;
    for(int i = 0; i < m; i++){
        sum += timeline[i];
        q.push(timeline[i]);
    }
    long long maxViewer = sum;
    
    // 구간을 1칸씩 이동하면서 구간합의 최대값을 구함
    // Two Pointer
    int advStart = 0;
    for(int i = m; i < n; i++){
        sum += timeline[i];
        q.push(timeline[i]);
        sum -= q.front();
        q.pop();
        
        if(sum > maxViewer){
            maxViewer = sum;
            advStart = i - m + 1;
        }
    }
    
    answer = secToStr(advStart);
    return answer;
}
