# 구현문제

def solution(survey, choices):
    answer = ''
    score_dict = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}  # 해당 유형별 점수 기록하는 dict
    for ty, c in zip(survey, choices):
        if c == 4:  # '모르겠음' 답변은 점수 없기에 무시한다
            continue

        score = c - 4  # 점수 계산
        if score > 0:  # 동의 의견이라면
            score_dict[ty[1]] += score
        else:
            # 비동의 의견
            score_dict[ty[0]] += abs(score)
    for ty in [['R', 'T'], ['C', 'F'], ['J', 'M'], ['A', 'N']]:
        if score_dict[ty[0]] < score_dict[ty[1]]:  # 후자 유형이 점수가 높다면
            answer += ty[1]
        else:  # 전자 유형의 점수가 높거나 전자와 후자 유형의 점수가 같다면
            answer += ty[0]

    return answer