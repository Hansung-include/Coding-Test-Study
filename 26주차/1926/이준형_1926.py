import sys
sys.setrecursionlimit(10 ** 6)

# def dfs(arr, info, cnt):
#
#     direction = [[0, 1], [1, 0], [-1, 0], [0, -1]]
#
#     for dir in direction:
#         x, y = info[0]+dir[0], info[1]+dir[1]
#
#         if 0<=x<len(arr) and 0<=y<len(arr[0]):
#             if not arr[x][y]:
#                 continue
#
#             else:
#                 if arr[x][y]:
#                     cnt = dfs(arr, [x, y], cnt+1)
#                     arr[x][y] = 0
#
#     return cnt


# bfs로 좌상단부터 탐색하며, 색칠된 그림의 넓이, 개수를 구하고
# max 연산을 통해 가장 큰 그림의 넓이를 구하게 된다.
def bfs(arr, visit, info, cnt):

    direction = [[0, 1], [1, 0], [-1, 0], [0, -1]]
    q = [info]
    while q:
        n, m = q.pop()
        for dir in direction:
            x, y = n+dir[0], m+dir[1]
            if 0<=x<len(arr) and 0<=y<len(arr[0]):
                if visit[x][y]:
                    continue

                visit[x][y] = 1

                if arr[x][y]:
                    q.append([x, y])
                    cnt += 1

    return cnt


n, m = map(int, sys.stdin.readline().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

visit = [[0 for _ in range(m)] for _ in range(n)]
answer = 0
picture = 0

for i in range(n):
    for j in range(m):
        if visit[i][j]:
            continue

        visit[i][j] = 1

        if arr[i][j]:
            picture += 1
            answer = max(answer, bfs(arr, visit, [i, j], 1))

print(picture)
print(answer)