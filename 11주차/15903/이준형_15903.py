
# 문제 링크 : https://www.acmicpc.net/problem/15903
# 1. x번 카드와 y번 카드를 골라 그 두 장에 쓰여진 수를 더한 값을 계산한다. (x ≠ y)
# 2. 계산한 값을 x번 카드와 y번 카드 두 장 모두에 덮어 쓴다.

import sys

# input
n, m = map(int, sys.stdin.readline().split())
a_list = list(map(int, sys.stdin.readline().split()))

for _ in range(m):
    a_list = sorted(a_list)  # 오름차순으로 정렬
    add = a_list[0] + a_list[1]  # 가장 작은 값을 뽑아 합친다.(1.)
    a_list[0] = a_list[1] = add  # 값을 덮어 쓴다.(2.)

print(sum(a_list))  # 합친 점수를 출력


