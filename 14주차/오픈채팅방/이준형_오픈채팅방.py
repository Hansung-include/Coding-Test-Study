def solution(record):
    answer = []
    user_dict = {}  # {user_id: user_name}
    for r in record:
        r = list(r.split(' '))
        if len(r) == 3:  # Enter, Change
            act, user_id, user_name = r
        else:  # Leave
            act, user_id = r
            # user_name = None
        if act == 'Enter':
            user_dict[user_id] = user_name
            answer.append([user_id, '님이 들어왔습니다.'])
        elif act == 'Leave':
            answer.append([user_id, '님이 나갔습니다.'])
        else:
            # Change: user_id 에 해당하는 닉네임을 변경한다
            user_dict[user_id] = user_name

    for i in range(len(answer)):  # 최종적으로 변경된 닉네임을 적용한다.
        user_id = answer[i][0]
        answer[i][0] = user_dict[user_id]
        answer[i] = answer[i][0] + answer[i][1]

    return answer



if __name__ == '__main__':
    record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    print(solution(record))