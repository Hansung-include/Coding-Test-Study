import sys
import copy

# 30968 KB, 192 ms
# 플루이드 와샬 기초 문제
# a->k, k->b 로 거쳐갈 수 있다면 1(True) 값을 설정해준다.

N = int(sys.stdin.readline())
graph_list = []
for _ in range(N):
    graph_list.append(list(map(int, sys.stdin.readline().split())))

answer = copy.deepcopy(graph_list)  # graph 와 copy 하여 만듦.

for k in range(N):
    for i in range(N):
        for j in range(N):
            if answer[i][j]:  # 이미 연결되어 있는 경우, 1일 경우에는 패스
                continue
            if answer[i][k] + answer[k][j] > 1:  # i->k, k->j 노드 둘다 연결이 되어 있는 경우
                answer[i][j] = 1

for i in range(N):
    for j in range(N):
        print(answer[i][j], end=' ')
    print()
