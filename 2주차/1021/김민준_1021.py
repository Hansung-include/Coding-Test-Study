from collections import deque
from sys import stdin

# deque 자료구조 => 양방향 큐
# queue와 달리 처음과 끝, 양쪽에서 pop과 push(append)가 가능하다

n, m = map(int, stdin.readline().split())
idx = list(map(int, stdin.readline().split()))  # 뽑을 인덱스 배열
deq = deque([i for i in range(1, n+1)])  # deque[1,2,3, ... , n]

cnt = 0
for i in idx:
    while True:
        # 뽑아내려는 인덱스가 처음 원소와 같을 경우
        # 맨 앞 element를 뽑기만 하면 끝난다
        if deq[0] == i:
            deq.popleft()
            break
        else:
            # 뽑아내려는 인덱스가 deque의 길이의 반보다 작을때
            # 왼쪽으로 밀어주는것이 더빠르다
            if deq.index(i) <= len(deq) // 2:
                deq.rotate(-1)
                cnt += 1
            else:
                deq.rotate(1)
                cnt += 1

print(cnt)
