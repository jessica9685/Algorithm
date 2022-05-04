// 2022_카카오 : 신고_결과_받기.js
function solution(id_list, report, k) {
    const answer = new Array(id_list.length);
    answer.fill(0);
    
    // 해당 유저를 신고한 id를 저장
    const report_obj = {};
    // map: 배열 내 모든 요소에 함수를 적용하는 메서드
    // report_obj = { id1:[], id2:[], ... }
    id_list.map (user => {
        report_obj[user] = [];
    })
    
    report.map(element => {
        const [user_id, report_id] = element.split(" ");
        // includes(id): id가 배열에 있으면 true
        // 중복제거를 위해 2번 이상 신고한 유저는 1회로 처리
        if(!report_obj[report_id].includes(user_id)){
           report_obj[report_id].push(user_id); 
        }
    })
    
    for(const key in report_obj){
        // k번 이상 신고당한 유저가 존재하면
        if(report_obj[key].length >= k){
            // 해당 유저를 신고한 모든 유저의 메일 개수 증가
            report_obj[key].map(user => {
                answer[id_list.indexOf(user)]++;
            })
        }
    }
    
    return answer;
}
