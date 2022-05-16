from sys import stdin

R, C = map(int, stdin.readline().split())

# '.' = 빈칸, 's' = 양, 'w' = 늑대
# 늑대가 양이 있는 칸으로 갈 수 없게 할 수 있다면 1출력
# 울타리는 'D'
# 늑대가 양한테 갈 수 있다면 0 출력

pasture = [list(input()) for _ in range(R)]  # 목장 상태 입력
move = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # 상,하,좌,우 좌표이동
flag = False

for i in range(R):
    for j in range(C):
        for (dy, dx) in move:
            if pasture[i][j] == 'S':
                x = j + dx
                y = i + dy

                if x < 0 or x >= C or y < 0 or y >= R:
                    continue
                if pasture[y][x] == 'W':
                    flag = True
                    break

if flag:
    print("0")
else:
    print("1")

    for i in range(R):
        for j in range(C):
            if pasture[i][j] == '.':
                pasture[i][j] = 'D'

    for i in pasture:
        print(''.join(i))
