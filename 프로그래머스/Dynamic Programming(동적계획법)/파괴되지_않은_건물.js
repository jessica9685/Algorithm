// 2022_카카오 : 파괴되지_않은_건물.js
// 누적합
function solution(board, skill) {
    // 누적합 배열
    const n = board.length, m = board[0].length;
    let sum = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));
    
    for(let s of skill){
        let [type, r1, c1, r2, c2, degree] = s;
        
        if(type === 1) degree = -degree; // attack
        
        // 시작점, (끝점 + 1)에 degree를 증가시키고, 나머지 두 꼭짓점에서는 degree를 감소시킴
        sum[r1][c1] += degree;
        sum[r2 + 1][c2 + 1] += degree;
        sum[r1][c2 + 1] -= degree;
        sum[r2 + 1][c1] -= degree;
    }
    
    // 누적합 합산
    // 1. 위에서 아래로 합산
    for(let r = 1; r < n; r++){
        for(let c = 0; c < m; c++){
            sum[r][c] += sum[r - 1][c];
        }
    }
    // 2. 왼쪽에서 오른쪽으로 합산
    for(let c = 1; c < m; c++){
        for(let r = 0; r < n; r++){
            sum[r][c] += sum[r][c - 1];
        }
    }
    
    // 무너지지 않은 건물 개수 세기
    let answer = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            board[i][j] += sum[i][j];
            if(board[i][j] > 0) answer++;
        }
    }
    return answer;
}
