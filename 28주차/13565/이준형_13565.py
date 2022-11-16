import sys
from collections import deque

# dfs
# 첫 줄에서 흰색의 공간의 인덱스를 따로 저장해
# 하나씩 for문을 돌면서 dfs로 주변에 퍼질수 있는 공간을 찾고
# 만약 가장 아래쪽에 도착한다면 True로 리턴하여 정답을 출력한다.


dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]


def dfs(arr, start, visited):
    h, w = len(arr), len(arr[0])
    q = deque([start])

    while q:
        pt = q.popleft()

        for d in dir:
            x, y = pt[0]+d[0], pt[1]+d[1]

            if 0<=x<h and 0<=y<w:
                if visited[x][y] or arr[x][y] == 1:
                    continue

                visited[x][y] = 1
                if x == h-1:
                    return True
                q.append([x, y])

    return False


m, n = map(int, sys.stdin.readline().split())
arr = []
q = deque()
visited = [[0 for _ in range(n)] for _ in range(m)]

for i, _ in enumerate(range(m)):
    row = list(map(int, sys.stdin.readline().rstrip()))
    if i == 0:
        [q.append([0, j]) for j, val in enumerate(row) if val == 0]
    arr.append(row)

answer = False
while q:
    start = q.popleft()
    answer = dfs(arr, start, visited)

    if answer:
        break

print('YES') if answer else print('NO')