from sys import stdin

N = int(input())
list = [list(map(str, stdin.readline().split())) for _ in range(N)]

# 나이가 같을 경우 순서 바뀌지 않음 (stable_sort)
list.sort(key=lambda x: int(x[0]))

for i in list:
    print(i[0], i[1])
