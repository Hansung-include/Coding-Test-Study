import sys
from collections import defaultdict, deque

# 39996 KB, 272 ms
# 키 순서대로 출력을 해야해서 간선의 방향을 작은키 -> 큰키로 구현했다.
# {작은키의 학생번호 : [작은키보다 큰 키의 학생번호, ,, , ,]}
# 또한 데이터를 입력 받을때 a 학생이 b 학생보다 작을 경우, b 학생은 자신 보다 작은 학생이 있다는 것을 체크한다.(+1)

N, M = map(int, sys.stdin.readline().split())
heights = defaultdict(list)
in_list = [0] * (N)
que = deque()
answer = []

for _ in range(M):
    short, tall = map(int, sys.stdin.readline().split())
    heights[short].append(tall)
    in_list[tall-1] += 1

for idx, cnt in enumerate(in_list):
    if cnt == 0:
        que.append(idx+1)


# 큐로 구현
while que:
    node = que.popleft()
    answer.append(node)
    for nxt in heights[node]:
        in_list[nxt-1] -= 1
        if in_list[nxt-1] == 0:
            que.append(nxt)


for a in answer:
    print(a, end=' ')