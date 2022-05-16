
# 38548 kb, 156 ms
# 연속되는 합을 구하기 위해 dp[i] 에는 dp[i-1] + n_list[i] 와 n_list[i] 중에 큰 값을 저장한다.
# 이렇게 해서 dp[i] 와 dp[0]~dp[i] 중 max 값을 구하여 max 값을 업데이트 한다.
# 최종적으로 끝까지 iteration 을 돌면서 max 값을 구하게 된다.

import sys

N = int(sys.stdin.readline())
n_list = list(map(int, sys.stdin.readline().rstrip().split()))

dp = []
max_val = n_list[0]

for idx, n in enumerate(n_list):
    if idx > 0:
        dp.append(max(dp[idx-1] + n, n))
    else:
        dp.append(n)
    max_val = max(max_val, dp[idx])

print(max_val)
