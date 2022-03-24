from sys import stdin
from collections import Counter

N = int(input())
list = [int(input()) for _ in range(N)]

list.sort()

avg = round(sum(list) / N)   # 산술 평균
median = list[N // 2]        # 중앙값

mode_list = Counter(list).most_common()
mode = mode_list[0][0]       # 최빈값

if len(mode_list) > 1:
    if mode_list[0][1] == mode_list[1][1]:
        mode = mode_list[1][0]

dist = list[-1] - list[0]    # 범위

print(avg, median, mode, dist, sep='\n')
