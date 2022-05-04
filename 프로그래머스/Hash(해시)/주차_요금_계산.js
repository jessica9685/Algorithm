// 2022_카카오 : 주차_요금_계산.js
function solution(fees, records) {
    // 기본시간, 기본요금, 단위시간(분), 단위요금
    const [basicTime, basicFee, min, unitFee] = fees;
    const cars = {}; // 각 차의 총 주차 시간
    const in_car = {}; // 주차장에 들어간 차와 시간
    
    
    // let: 수정 가능한 변수 (var보단 엄격하지만 const보단 느슨)
    // for ~ of: 배열 순환
    // for ~ in: 객체 순환
    for(let record of records) {
        const [time, car_num, state] = record.split(" ");
        const [hour, min] = time.split(":").map(t => Number(t));
        
        // 들어오는 차는 객체에 추가
        if(state == "IN") in_car[car_num] = [hour, min];
        else { // 차가 나갈 때
            let in_time = in_car[car_num];
            let total_time = (hour - in_time[0]) * 60 + min - in_time[1];
            if(car_num in cars) cars[car_num] += total_time;
            else cars[car_num] = total_time;
            
            // 들어오는 차 속성 삭제
            delete in_car[car_num];
        }
    }
    
    // Object.entries(obj): [key, value] 쌍의 배열을 반환
    // for (let [key, value] of Object.entries(obj)){}
    for(let [remain_car, time] of Object.entries(in_car)){
        let total_time = (23 - time[0]) * 60 + 59 - time[1];
        if(remain_car in cars) cars[remain_car] += total_time;
        else cars[remain_car] = total_time;
    }
    
    const answer = [];
    for(let [car, time] of Object.entries(cars)){
        let fee = 0; 
        if(time <= basicTime) fee = basicFee;
        else{
            // 단위시간으로 나누어 떨어지지 않으면 올림
            fee = basicFee + Math.ceil((time - basicTime) / min) * unitFee;
        }
        answer.push([car, fee]);
    }
    
    // 차량번호 기준 오름차순 정렬 후 요금만 배열로 저장
    return answer.sort((a, b) => a[0] - b[0]).map(arr => arr[1]);
}
