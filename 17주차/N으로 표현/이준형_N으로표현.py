# dp 문제
# 숫자를 몇 개 사용했는지를 인덱스로 하고 문제에서 주어진 수가 찾아지면 그때의 개수를 출력.


def solution(N, number):
    answer = 0
    dp = [0, [N]]  # 1개를 사용했을때의 나타나는 경우의 수
    use_num = 1
    if N == number:  # 1개로 number 를 찾았을 경우
        answer = 1

    while not answer:
        num_list = []
        use_num += 1
        if use_num > 8:
            answer = -1

        else:
            num_list.append(int(str(N) * use_num))  # 5, 55, 555, 사칙연산을 제외한 숫자

            for i, dp_prev in enumerate(dp[:use_num // 2 + 1]):  # dp 값에 저장되어 있는 값으로 업데이트
                if i == 0:
                    continue
                for prev in dp_prev:
                    for pprev in dp[use_num - i]:
                        num_list.append(prev + pprev)
                        if abs(prev - pprev) > 0:
                            num_list.append(abs(prev - pprev))

                        num_list.append(prev * pprev)
                        if prev // pprev > 0:
                            num_list.append(prev // pprev)
                        elif pprev // prev > 0:
                            num_list.append(pprev // prev)

            num_list = set(num_list)  # 중복 삭제

            for n in num_list:
                if n == number:  # 찾고자 하는 값을 찾으면 리턴
                    answer = use_num

            dp.append(num_list)

    return answer


if __name__ == '__main__':
    print(solution(5, 12))
    print(solution(2, 11))
    print(solution(4, 31))