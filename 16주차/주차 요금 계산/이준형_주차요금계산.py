def solution(fees, records):
    answer = []
    car = {}  # 차량번호: [누적주차시간, 입차시간, 입차or출차]

    # 주차 시간 계산
    for record in records:
        time, car_num, act = record.split(' ')
        if car_num not in car:
            car[car_num] = [0, time, act]

        elif act == 'IN':
            car[car_num][1] = time
            car[car_num][2] = act

        elif act == 'OUT':  # 출차시간 - 입차시간 분으로 환산
            car[car_num][2] = act
            in_time = [int(car[car_num][1][:2]), int(car[car_num][1][3:])]
            out_time = [int(time[:2]), int(time[3:])]
            total_time = (out_time[0] * 60 + out_time[1]) - (in_time[0] * 60 + in_time[1])
            car[car_num][0] += total_time

    # 누적주차시간을 토대로 주차요금 정산
    answer_info = []
    for car_num, info in car.items():
        if info[-1] == 'IN':  # 아직 출차기록이 없다면
            in_time = [int(info[1][:2]), int(info[1][3:])]
            total_time = (23 * 60 + 59) - (in_time[0] * 60 + in_time[1])
            info[0] += total_time

        if info[0] <= fees[0]:  # 기본 요금
            fee = fees[1]
        else:  # 기본 요금 + 추가 요금
            over_time = info[0] - fees[0]
            if over_time / fees[2] != int(over_time / fees[2]):
                over_time_per = int(over_time / fees[2]) + 1
            else:
                over_time_per = over_time // fees[2]
            fee = fees[1] + over_time_per * fees[3]

        answer_info.append([car_num, fee])
    answer_info = sorted(answer_info, key=lambda x: x[0])

    for a in answer_info:
        answer.append(a[1])
    return answer


if __name__ == '__main__':
    fees = [180, 5000, 10, 600]
    records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
    print(solution(fees, records))