// 2022_카카오 : 사라지는_발판.js
const dy = [1, -1, 0, 0];
const dx = [0, 0, 1, -1];

// 이동 가능하면 true
function canMove(loc, board){
    const n = board.length, m = board[0].length;
    
    // 자신의 발판이 없으면 이동 불가
    if(board[loc[0]][loc[1]] === 0) return false;
    for(let d = 0; d < 4; d++){
        const ny = loc[0] + dy[d];
        const nx = loc[1] + dx[d];
        
        // 이동할 발판이 있으면 true
        if(ny >= 0 && nx >= 0 && ny < n && nx < m) {
            if(board[ny][nx] === 1) return true;
        }
    }  
    return false;
}

// 현재 차례인 플레이어의 위치: cur, 다음 차례 플레이어 위치: next
// 현재 플레이어의 승리 여부 & 최적의 플레이 횟수 반환
function dfs(board, cur, next){
    // 더이상 움직일 수 없으면 cur의 패배
    if(!canMove(cur, board)) return [false, 0];
    
    let canWin = false; // cur이 이기면 true
    let minTurn = 25, maxTurn = 0; // 최소, 최대 턴 수
    const n = board.length, m = board[0].length;
    
    for(let d = 0; d < 4; d++){
        const ny = cur[0] + dy[d];
        const nx = cur[1] + dx[d];
        
        // 범위를 벗어나면 패스
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(board[ny][nx] === 0) continue; // 발판 X -> 패스
        
        board[cur[0]][cur[1]] = 0; // 이동
        let result = dfs(board, next, [ny, nx]); // 이동 결과
        board[cur[0]][cur[1]] = 1; // backtracking
        
        // 이길 수 있으면 최소 턴 수
        if(!result[0]) {
            canWin = true;
            minTurn = Math.min(minTurn, result[1]);
        }
        // 이길 수 없으면 최대 턴 수
        else maxTurn = Math.max(maxTurn, result[1]);      
    }
    
    // 승리 가능하면 최소, 불가능하면 최대 턴 수 리턴
    let turnCnt = canWin ? minTurn : maxTurn;
    return [canWin, turnCnt + 1];
}

function solution(board, aloc, bloc) {   
    let answer = dfs(board, aloc, bloc);
    
    return answer[1];
}
