import sys

# 순위가 높은순으로 정렬을 한 후에 이를 본인 순위로 생각하여 불만도를 최소화 했다.

N = int(sys.stdin.readline())
wants = []
for _ in range(N):
    wants.append(int(sys.stdin.readline()))

wants = sorted(wants)
total_angry = 0
for idx, rank in enumerate(wants):
    angry = abs(idx+1 - rank)
    if angry:
        total_angry += angry

print(total_angry)