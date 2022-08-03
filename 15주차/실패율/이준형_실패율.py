def solution(N, stages):
    answer = []
    stage_list = [0 for _ in range(N + 1 + 1)]  # idx: 스테이지 번호, stage_list[idx]: 해당 스테이지에 몇 명이 있는지
    user_num = len(stages)  # 총 전체 인원
    failure_list = [[i, 0] for i in range(N + 1 + 1)]  # [[스테이지 번호, 실패율], , , , ]

    for s in stages:  # stage_list 만들기
        stage_list[s] += 1

    for i, n in enumerate(stage_list[:-1]):  # 실패율 구하기
        if user_num == 0:  # 해당 스테이지에 통과하거나 도전하는 사람이 없다면
            break  # 실패율은 0이다.
        failure_list[i][1] = n / user_num
        user_num -= n

    failure_list = failure_list[1:-1]  # 0 스테이지와, N+1 스테이지는 범위에 벗어나므로 제외
    failure_list = sorted(failure_list, key=lambda x: -x[1])  # 실패율이 높은 내림차순으로 정렬

    for stage, failure in failure_list:
        answer.append(stage)
    return answer


if __name__ == '__main__':
    # print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))
    print(solution(5, [1, 1, 1, 1, 1, 1, 1, 1]))