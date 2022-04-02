import sys

N = int(sys.stdin.readline())
n_list = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline())

# 30864 KB, 112 ms
# 시작값 (0) ~ 마지막 값 (예산 요청의 최대값) 으로 하여 중간값을 상한액이라 가정하자
# 상한액에 대해 총액과 비교하며 시작값, 마지막값을 업데이트하며 최대 예산 금액을 찾는다.

if sum(n_list) <= M:
    print(max(n_list))

else:
    start = 0
    end = max(n_list)
    check_sum = 0
    while start <= end:
        check_sum = 0
        max_money = (start+end) // 2
        for i in range(N):
            check_sum += min(max_money, n_list[i])
        if check_sum > M:
            end = max_money - 1
        else:
            start = max_money + 1

    print(end)  # end 값이 최대 상한액이다.
