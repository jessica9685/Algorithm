// 2022_카카오 : 양궁대회.js
function solution(n, info) {
    let answer = new Array(11).fill(0);
    let max_diff = 0; // 최대 점수 차이 
    
    // 0점부터 탐색
    function dfs(apeach_score, ryan_score, point, cnt, ryan){
        // 화살의 개수가 n을 넘어가면 종료
        if(cnt > n) return;

        // 마지막 과녁까지 탐색 완료했을 때
        if(point > 10){ 
            let diff = ryan_score - apeach_score;
            if(max_diff < diff){ // 최대값 갱신
                // 남은 화살은 0점에 넣기
                ryan[10] = n - cnt;
                max_diff = diff;
                answer = ryan;
            }
            return;
        }
    
        // 라이언이 point점을 얻는 경우
        if(cnt < n){
            let cur = [...ryan];
            cur[10 - point] = info[10 - point] + 1;
            dfs(apeach_score, ryan_score + point, point + 1, cnt + info[10 - point] + 1, cur);
        }
        
        // 어피치가 point점을 얻는 경우
        if(info[10 - point] > 0){
            dfs(apeach_score + point, ryan_score, point + 1, cnt, ryan)
        }
        // 둘 다 점수를 얻지 못하는 경우
        else dfs(apeach_score, ryan_score, point + 1, cnt, ryan); 
    }
    
    dfs(0, 0, 0, 0, answer);
    
    if(max_diff <= 0) return [-1];
    else return answer;
}
