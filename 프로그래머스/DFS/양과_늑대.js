// 2022_카카오 : 양과_늑대.js
function solution(info, edges) {
    let answer = 0;
    // from을 이용한 2차원 배열(벡터)
    // 노드 개수만큼 빈 배열을 생성
    // 20x10 배열: Array.from({length: 20}, () => Array(10).fill(0));
    let graph = Array.from({length: info.length}, () => []);
    
    // 각 노드의 연결 관계를 그래프(벡터) 형태로 나타냄
    for(const edge of edges){
        graph[edge[0]].push(edge[1]);
    }
    
    // 모든 경우의 수 탐색
    // cur: 현재 노드, sheep, wolf: 양, 늑대 수, go: 이동 가능한 노드 배열
    function dfs(cur, sheep, wolf, go){
        if(info[cur]) wolf++; // 현재 노드가 늑대인 경우
        else sheep++; // 현재 노드가 양인 경우
        
        // 최대값 갱신
        if(answer < sheep) answer = sheep;
        
        // (양 == 늑대)이면 종료
        if(wolf == sheep) return;
        
        // 다음 이동가능한 노드들을 배열에 추가
        let next = [...go];
        next.push(...graph[cur]);
        // 현재 노드는 배열에서 삭제
        // array.splice(index, cnt): index부터 cnt개만큼 원본 배열에서 삭제 
        // 원본 배열을 변경하지 않는 slice와 달리 splice는 원본 배열을 변경한다.
        next.splice(next.indexOf(cur), 1); 
        
        for(const node of next){
            dfs(node, sheep, wolf, next);
        }
    }
    
    dfs(0, 0, 0, [0]);
    
    return answer;
}
