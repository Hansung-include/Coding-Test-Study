import sys

# dp 알고리즘
# 30840 KB, 156 ms
# 1, 2, 3, ,,, N 순으로 dp 에 최소 금액을 찾고 값을 추가하며 N 까지 진행한다.

N = int(sys.stdin.readline())
p_list = list(map(int, sys.stdin.readline().split()))

# 초기값
dp = [p_list[0]]

# 1~N 까지 dp에 추가
for i in range(1, N):
    check_list = []  # min 값을 비교할 체크리스트
    if i < len(p_list):  # p_list 에 존재한다면
        check_list.append(p_list[i])

    for j in range((i+1)//2):  # 4 개를 사고 싶을때 -> dp[0] + dp[3], dp[1] + dp[2] 를 check_list 에 추가함
        # 인덱스 주의
        check_list.append(dp[j] + dp[i-(j+1)])

    # 추가한 체크리스트의 최소 금액을 불러옴
    min_value = min(check_list)
    dp.append(min_value)

print(dp[N-1])