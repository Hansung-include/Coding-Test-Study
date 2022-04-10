from sys import stdin

N = int(input())
req = list(map(int, stdin.readline().split()))
M = int(input())
start, end = 0, max(req)

while start <= end:
    mid = (start + end) // 2
    total = 0

    for i in req:
        if i > mid:
            total += mid
        else:
            total += i

    if total <= M:
        start = mid + 1
    else:
        end = mid - 1

print(end)
