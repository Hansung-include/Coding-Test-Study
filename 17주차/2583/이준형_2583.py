
# DFS 문제
# 좌상단, 우하단 좌표로 변경한뒤 모눈종이에 직사각형을 칠한다.
# 모눈종이를 좌상단부터 우하단순으로 확인하며 빈칸을 발견했을때 그 주변값을 확인한다.

import sys
from collections import deque

M, N, K = map(int, sys.stdin.readline().split())
paper = [[0 for _ in range(N)] for _ in range(M)]
for _ in range(K):
    lx, ly, rx, ry = map(int, sys.stdin.readline().split())
    # index left top
    ltx, lty = lx, M-ry
    rbx, rby = rx, M-ly
    for x in range(ltx, rbx):
        for y in range(lty, rby):
            paper[y][x] = 1

visited = [[0 for _ in range(N)] for _ in range(M)]

answer = []
for x in range(N):
    for y in range(M):
        if paper[y][x] or visited[y][x]:
            continue
        will_visit = deque([[y, x]])  # 빈칸을 발견했을때의 그 주변 빈칸을 담을 큐
        visited[y][x] = 1
        count = 0
        while will_visit:
            y, x = will_visit.popleft()
            count += 1
            for dir in ((-1,0), (1,0), (0,-1), (0,1)):  # 상하좌우 빈칸인지 체크
                if 0 <= y+dir[0] < M and 0 <= x+dir[1] < N:
                    if not visited[y+dir[0]][x+dir[1]] and not paper[y+dir[0]][x+dir[1]]:  # 방문하지도 않았고 빈칸이면
                        will_visit.append((y+dir[0], x+dir[1]))  # 큐에 넣고
                        visited[y+dir[0]][x+dir[1]] = 1  # 방문예정이라고 체크
        if count:
            answer.append(count)

answer = sorted(answer)
print(len(answer))
for i in answer:
    print(i, end=' ')


