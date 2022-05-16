# DP

N = int(input())
dp = [0] * 16
for i in range(1, N+1):
    term, price = map(int, input().split())
    if i+term-1 <= N:  # 데드라인을 안넘길때
        dp[i+term-1] = max((max(dp[:i]) + price), dp[i+term-1])
print(max(dp))
