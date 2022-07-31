// 2022_카카오 : k진수에서_소수_개수_구하기.js
// 소수 판별 함수
function isPrime(num){
    if(num == 1) return false;
    if(num == 2) return true;
    
    // num의 제곱근까지 확인
    for(let i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

function solution(n, k) {
    let answer = 0;
    
    // k진수로 변환
    let knum = n.toString(k);
    // 0을 구분자로 split
    let numbers = knum.split("0"); // 빈 문자열이 포함됨
    
    for(number of numbers){
        let num = parseInt(number);
        if(isNaN(num)) continue; // 빈 문자열이면 패스
        
        // 소수이면 개수 증가
        if(isPrime(num)) answer++;
    }
    
    return answer;
}
