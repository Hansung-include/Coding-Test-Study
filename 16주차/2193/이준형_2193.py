# 이친수

# dp
# 점화식 dp[n] = dp[n-2] + dp[n-1]

import sys

n = int(sys.stdin.readline())

dp = [1, 1]
if n>2:
    for k in range(2, n):
        dp.append(dp[k-2] + dp[k-1])

print(dp[n-1])