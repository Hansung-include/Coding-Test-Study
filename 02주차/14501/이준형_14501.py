import sys

# 이름: 이준형
# 언어: python
# 문제 링크: https://www.acmicpc.net/problem/14501

# 1일차 상담부터 가능한 모든 경우의 수를 dfs방식으로 수익을 계산하여 최고의 수익을 찾는다.

N = int(sys.stdin.readline())
consults = []  # 상담 리스트
max_profits = 0
for _ in range(N):
    t, p = map(int, sys.stdin.readline().split())
    consults.append([t, p])  # [시간, 수익] 형식으로 추가함

def dfs(idx, profits=0, max_profits=0):  # profits: 현재 상담받은 수익, max_profits: 가장 최고의 수익
    if idx < N:  # N일차 까지만 상담 가능
        time, profit = consults[idx]
        for i in range(idx+time, N+1):  # N일차 초과가 되면 상담 불가능
            max_profits = dfs(i, profits + profit, max_profits)  # dfs 한 결과 업데이트
    return max(max_profits, profits)  # 최고의 수익을 리턴한다.


for k in range(N):  # 시작 날짜를 순차적으로 다르게끔 해서 dfs를 시작한다.
    max_profits = max(max_profits, dfs(k))

print(max_profits)
