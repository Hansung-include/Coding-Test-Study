# https://www.acmicpc.net/problem/2644

# dict 로 그래프를 만들어서 bfs로 해결
# 노드 1 과 노드 2의 관계를 찾고 싶을때
# 노드 1의 주변(부모, 자식노드)을 탐색하여 노드 2를 찾는다.

import sys
from collections import deque


class Node:
    def __init__(self, num):
        '''노드의 해당 번호, 부모, 자식을 따로 리스트로 저장한다.'''
        self.num = num
        self.parent = []
        self.child = []


def search(dict, node, previous_node, find_node, cnt):
    '''노드 1 과 노드 2 가 일치하는지 찾는 함수'''
    # dict: 그래프, node: 현재 체크할 노드, previous_node: node 가 어디에서 왔는지(방문했던 노드)
    # find_node: 우리가 찾고 싶은 노드(노드 2), cnt: 촌수

    result = -1  # 기본 값 -1 -> 찾지 못한다는 가정으로 초기화
    if node == find_node:
        return cnt  # 노드 1과 노드 2가 일치한다면 그때의 촌수를 리턴해준다.

    que = deque(dict[node].child)  # 주변(자식)노드 추가
    que.extend(dict[node].parent)  # 주변(부모)노드 추가
    que.remove(previous_node)  # bfs 에서의 visited 라고 볼 수 있다. 방문했던 노드를 제거해줌
    while que:
        result = search(dict, que.pop(), node, find_node, cnt + 1)
        if result != -1:  # 노드 2를 찾았다면
            break
    return result

relation_dict = {}

n = int(sys.stdin.readline())
a, b = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())
for _ in range(k):
    x, y = map(int, sys.stdin.readline().split())
    # 그래프 생성 및 해당 노드의 자식, 부모 노드 값 할당
    if x not in relation_dict:
        relation_dict[x] = Node(x)
    if y not in relation_dict:
        relation_dict[y] = Node(y)
    relation_dict[x].child.append(y)
    relation_dict[y].parent.append(x)

q = deque()
q.extend(relation_dict[a].parent)
q.extend(relation_dict[a].child)

while q:
    n = q.pop()
    answer = search(relation_dict, n, a, b, cnt=1)
    if answer != -1:
        break

print(answer)

