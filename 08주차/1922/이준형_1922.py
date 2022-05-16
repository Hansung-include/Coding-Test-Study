import sys

# union_find 로 크루스칼 알고리즘을 구현한다.

# 파이썬으로 union_find 구현 https://url.kr/b3uv69

# 특정 노드의 부모 노드를 찾는 함수
def find_parent(cycle_table, node):
    if cycle_table[node] != node:
        return find_parent(cycle_table, cycle_table[node])
    return node

# 노드1, 노드2 를 연결시켜준다
def union(cycle_table, node1, node2):
    node1_parent = find_parent(cycle_table, node1)
    node2_parent = find_parent(cycle_table, node2)

    if node1_parent == node2_parent:  # 사이클이 형성되었을때
        return cycle_table, False

    # 부모 노드 업데이트
    if node1_parent > node2_parent:
        cycle_table[node1_parent] = node2_parent
    else:
        cycle_table[node2_parent] = node1_parent

    return cycle_table, True


N = int(sys.stdin.readline())
M = int(sys.stdin.readline())

cycle_table = {}
cost_list = []
answer = 0

for _ in range(M):
    com1, com2, cost = map(int, sys.stdin.readline().split())
    cost_list.append([com1, com2, cost])

    for com in [com1, com2]:
        if com not in cycle_table:
            cycle_table[com] = com

cost_list = sorted(cost_list, key=lambda x: x[-1])  # 비용이 작은 순으로 나열함


for com1, com2, cost in cost_list:
    if com1 == com2:  # 같은 노드라면 패스한다
        continue
    cycle_table, result = union(cycle_table, com1, com2)
    if result:  # 사이클이 아닐 경우에만
        answer += cost


print(answer)
