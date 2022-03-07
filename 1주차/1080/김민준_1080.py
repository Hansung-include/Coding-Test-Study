from sys import stdin
n, m = map(int, stdin.readline().split())

a = []
b = []
for _ in range(n):
    a.append(list(map(int, list(input()))))
for _ in range(n):
    b.append(list(map(int, list(input()))))


def toggle(i, j):
    for x in range(i, i+3):  # i부터 i+2까지
        for y in range(j, j+3):
            a[x][y] ^= 1  # xor, (0=>1, 1=>0)


cnt = 0
# 행과 열이 3보다 작고,
# 둘의 행렬이 다를경우 변환 불가
if(n < 3 or m < 3) and a != b:
    cnt = -1
else:
    for x in range(n-2):
        for y in range(m-2):
            if a[x][y] != b[x][y]:
                toggle(x, y)
                cnt += 1

if a != b:
    cnt = -1

print(cnt)
