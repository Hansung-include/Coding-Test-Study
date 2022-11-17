import sys

# 이분 탐색
# left를 최소 길이 1로, right를 막대기의 최대 길이로 두어
# 가장 최대 길이로 모든 사람들에게 나누어줄 수 있는 경우를 포함.

m, n = map(int, sys.stdin.readline().split())
n_list = list(map(int, sys.stdin.readline().split()))

l = 1
r = max(n_list)

while l <= r:
    length = (l+r)//2

    cnt = 0
    for n in n_list:
        cnt += n // length

    if cnt >= m:
        l = length+1
    else:
        r = length-1
print(r)
