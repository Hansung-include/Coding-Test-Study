def solution(id_list, report, k):
    answer = [0] * len(id_list)
    reported_num_dict = {}  # 신고당한 횟수
    reports_dict = {}  # 어떤 유저가 어떤 유저를 신고했는지

    # 초기화
    for id_ in id_list:
        reported_num_dict[id_] = 0
        reports_dict[id_] = []

    for r in report:
        id_, reported_id = r.split()  # 유저, 신고당한 유저
        if reported_id not in reports_dict[id_]:  # 신고가 되어 있지 않다면
            reports_dict[id_].append(reported_id)
            reported_num_dict[reported_id] += 1  # 신고 횟수 추가

    for id_ in id_list:
        if k <= reported_num_dict[id_]:  # k번 이상 신고당했다면
            stopped = id_
            for idx, id_name in enumerate(id_list):
                if stopped in reports_dict[id_name]:  # 유저가 정지 유저를 신고했다면
                    answer[idx] += 1  # 메일 발송 카운트 추가
    return answer


if __name__ == '__main__':
    print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"], 2))  # [2, 1, 1, 0]