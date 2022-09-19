# 민우가 구매한 lotto 번호가 몇개가 일치하는지 우선 체크하고
# 알아볼 수 없는 숫자가 전부 맞췄다면 -> 최고 순위, 다 틀렸다면 -> 최저 순위로 계산

def solution(lottos, win_nums):
    answer = []
    lotto_dict = {6: 1, 5: 2, 4: 3, 3: 4, 2: 5}  # {맞춘 개수: 순위}
    answer_cnt = 0
    zero_cnt = 0

    # 민우가 구매한 lotto 번호가 몇개가 일치하는지 체크
    for n in win_nums:
        if n in lottos:
            answer_cnt += 1

    # 알아볼 수 없는 숫자가 몇개인지 체크
    for n in lottos:
        if n == 0:
            zero_cnt += 1

    for i in [zero_cnt + answer_cnt, answer_cnt]:  # [최고 순위, 최저 순위]
        if i in lotto_dict:
            num = lotto_dict[i]
        else:
            num = 6

        answer.append(num)

    return answer