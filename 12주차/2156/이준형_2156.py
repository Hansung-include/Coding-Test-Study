import sys

n = int(sys.stdin.readline())
n_list = []
for _ in range(n):
    n_list.append(int(sys.stdin.readline()))

dp = [n_list[0]]
if n > 1:
    dp.append(n_list[0] + n_list[1])

for i in range(2, n):
    if i-3 < 0:
        dp.append(max(n_list[0]+n_list[2], n_list[1]+n_list[2]))
    else:
        dp.append(max(dp[i-3]+n_list[i-1], dp[i-2]) + n_list[i])  # 연속 세 잔을 안마시는 조건
    dp[-1] = max(dp[-1], dp[-2])  # 현재 i 번째보다 i-1 번째 값이 더 클경우 업데이트

print(dp[-1])