import sys

# 이름: 이준형
# 언어: python
# 문제 링크: https://www.acmicpc.net/problem/1021

# 큐의 길이의 절반으로 나눴을때 뽑아내려고 하는 수가 왼쪽에 있다면 move_left 연산을 수행하고
# 오른쪽에 있다면 move_right 연산을 수행한다.

def move_left(queue_list):
    """ 왼쪽으로 이동시키는 연산 """
    queue_list[0:-1], queue_list[-1] = queue_list[1:], queue_list[0]

def move_right(queue_list):
    """ 오른쪽으로 이동시키는 연산 """
    queue_list[1:], queue_list[0] = queue_list[0:-1], queue_list[-1]


answer = 0
N, M = map(int, sys.stdin.readline().split())
remove_list = list(map(int, sys.stdin.readline().split()))
n_list = [i+1 for i in range(N)]

for i in remove_list:
    idx = n_list.index(i)  # 파라미터 값이 리스트에서 몇 번째 인덱스인지 검색해준다.
    if idx != 0:
        if idx > len(n_list) // 2:
            for _ in range(len(n_list)-idx):
                move_right(n_list)
                answer += 1
        else:
            for _ in range(idx):
                move_left(n_list)
                answer += 1
    del n_list[0]  # 뽑아냄


print(answer)