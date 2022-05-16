import sys
from collections import deque

# python
# 78676 KB, 2152 ms
# 순간이동, -1, +1 방향으로 이동 가능하다면 어느때건 이동하자
# 방문한 칸을 따로 저장하여 한번씩만 방문하게끔하자

N, K = map(int, sys.stdin.readline().split())


def bfs(k, q):
    answer = sys.maxsize
    visited = [False for _ in range(100001)]

    while q:
        n, sec = q.popleft()
        visited[n] = True
        if n*2 == k:
            answer = min(answer, sec+1)

        diff = abs(n-k)
        answer = min(answer, sec+diff)

        shift = abs(n*2-k)
        if diff > shift:  # 순간이동(2*n) 만큼 이동하는게 더 적게 걸린다면
            if n*2 <= 100000:
                if not visited[n*2]:
                    q.append([n * 2, sec + 1])

        for i in [-1, 1]:
            if 0 <= n+i <= 100000:
                if visited[n+i]:
                    continue
                q.append([n+i, sec + 1])
    return answer

q = deque([[N, 0]])
answer = bfs(K, q)
print(answer)
