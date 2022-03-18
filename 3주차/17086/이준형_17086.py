import sys
from collections import deque

# 많은 시간 소요 32428 KB / 7556 ms
# 좌상단부터 한칸씩 상어와의 거리를 계산하여 최대 값을 구해보자
# bfs 로 주변 거리를 하나씩 탐색하는 방식으로 거리를 계산했다.
# 모든 칸의 상어와 거리를 계산하다보니 시간이 오래걸려 cost 가 높다고 판단.

N, M = map(int, sys.stdin.readline().split())
space = []

for _ in range(N):
    space.append(list(map(int, sys.stdin.readline().split())))

dir = ((0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1))
count = 0
answer = 0


def bfs(que, visited, answer):
    while que:
        i, j, cnt = que.popleft()
        for d in dir:
            x, y = i+d[0], j+d[1]

            if x<0 or x>=N or y<0 or y>=M:
                continue

            if space[x][y] == 1:  # 상어와 마주침
                answer = max(cnt+1, answer)  # 최대 거리
                return answer

            if not visited[x][y]:  # 방문하지도 않고 상어가 없는 자리라면 또 방문해야함
                q.append((x, y, cnt+1))  # 큐에 추가

            visited[x][y] = True  # 방문했다고 저장

    return answer


for i in range(N):
    for j in range(M):
        if space[i][j] == 1:
            continue

        q = deque()  # 선입 선출
        visited = [[False for _ in range(M)] for _ in range(N)]  # 방문했는지 저장하는 변수
        visited[i][j] = True
        q.append((i, j, 0))  # (x좌표, y좌표, 상어와의 거리)
        count = max(count, bfs(q, visited, answer))


print(count)