import sys

# 좌상단부터 a 와 b 행렬의 원소값을 비교하여 다르다면 바로 바꿔준다.

# 못풀었던점: 어떤 위치부터 바꿔야 하는지??
# 해결: 교환법칙이 성립하기에 어떤 위치부터 바꾸는건 중요하지 않다.


N, M = map(int, sys.stdin.readline().split())
a = []
b = []
cnt = 0

for i in range(N*2):
    row = list(map(int, sys.stdin.readline().rstrip()))  # 입력이 12345 -> [1, 2, 3, 4, 5] 바꿔줌
    if i < N:
        a.append(row)
    else:
        b.append(row)


def change_num(i, j):
    for x in range(i, i+3):
        for y in range(j, j+3):
            a[x][y] ^= 1


if N < 3 or M < 3:
    if a == b:  # 3보다 작아도 같다면 답이 -1 이 아니라 0이다.
        cnt = 0
    else:
        cnt = -1
else:
    for i in range(N-2):
        for j in range(M-2):
            if a[i][j] != b[i][j]:
                change_num(i, j)
                cnt += 1

if a != b:
    cnt = -1

print(cnt)
