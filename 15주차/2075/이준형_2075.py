# N 번째 큰 수

import sys
# from queue import PriorityQueue
import heapq

N = int(sys.stdin.readline())
arr = []
# q = PriorityQueue()
hq = []
for _ in range(N):
    # arr.append(list(map(int, sys.stdin.readline().split())))
    row = list(map(int, sys.stdin.readline().split()))

    # 우선순위 큐의 길이를 항상 N 의 길이만큼 조절한다(메모리 때문)
    if not hq:
        for r in row:
            heapq.heappush(hq, r)
    else:
        for r in row:
            if hq[0] < r:
                heapq.heappush(hq, r)
                heapq.heappop(hq)
# 메모리 초과
# find_list = arr[-1]
# find_list_idx = [N-1 for _ in range(N)]
# for _ in range(N):
#     max_val = max(find_list)
#     max_idx = find_list.index(max_val)
#     find_list_idx[max_idx] -= 1
#     find_list[max_idx] = arr[find_list_idx[max_idx]][max_idx]
#
# print(max_val)

# for _ in range(N):
    # val = heapq.heappop(hq)

print(hq[0])
