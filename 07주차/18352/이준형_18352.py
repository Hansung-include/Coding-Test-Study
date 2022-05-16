import sys
from collections import deque, defaultdict

# 144828 KB, 2852 ms
# bfs 로 시작 노드에서 출발해서 갈 수 있는 노드를 모두 탐색하면서 해당 노드에 최단 거리를 찾을때마다 값을 갱신한다.

N, M, K, X = map(int, sys.stdin.readline().split())
way_arr = defaultdict(list)  # {출발노드 : [도착노드1, 도착노드2, 도착노드3, ,,,]}
fast_way = defaultdict(int)  # {노드 : 최단거리}

for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    # 단방향 데이터 추가
    if way_arr[A]:
        way_arr[A].append(B)
    else:
        way_arr[A] = [B]

que = deque([[0, X]])

# bfs 방식으로 탐색
while que:
    distance, visit = que.popleft()

    for idx, way in enumerate(way_arr[visit]):
        if fast_way[way]:  # 최단 거리 dict 에 저장이 되었을 경우
            if distance+1 < fast_way[way]:  # 최소 거리로 계산되었을 경우 큐에 추가함
                que.append([distance + 1, way])
        else:  # 최단 거리 dict 에 저장이 안되었을 경우
            fast_way[way] = distance + 1
            que.append([distance+1, way])

exist_k = []
for node, distance in fast_way.items():
    if distance == K and node != X:  # 시작 노드가 다른 노드를 거쳐 시작 노드에 다시 도달했을 경우를 제외
        exist_k.append(node)

if exist_k:
    exist_k = sorted(exist_k)
    for i in exist_k:
        print(i)
else:
    print(-1)