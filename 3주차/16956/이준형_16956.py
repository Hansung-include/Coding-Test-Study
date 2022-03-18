import sys

# 늑대 주변을 울타리로 설치하자
# 늑대 옆에 양이 있다면 0 출력, 늑대가 없거나 양이 없다면 1 출력

R, C = map(int, sys.stdin.readline().split())
farm = []

for _ in range(R):
    farm.append(list(sys.stdin.readline().rstrip()))

safe = True  # 늑대로부터 안전하다는 변수

def install_fence(i, j):
    """ 늑대 주변(위, 아래, 양옆)에 울타리를 설치 """
    dir = ((0, -1), (-1, 0), (0, 1), (1, 0))
    possible = True  # 울타리 설치가 가능여부를 따지는 변수

    for d in dir:
        x, y = d[0]+i, d[1]+j
        if 0<=x<R and 0<=y<C:
            if farm[x][y] == 'S':  # 늑대 옆에 양이 있는 경우
                possible = False  # 늑대가 양에게 갈 수 있으므로 false 값 할당
                break
            elif farm[x][y] != 'W':  # 늑대 옆에 늑대가 아닐 경우만 울타리 설치
                possible = True
                farm[x][y] = 'D'

    return possible


for i in range(R):
    for j in range(C):
        if farm[i][j] == 'W':
            safe = install_fence(i, j)

        if not safe:  # 양과 늑대가 인접해있으므로 반복문 탈출
            break

    if not safe:  # 양과 늑대가 인접해있으므로 반복문 탈출
        break


if safe:
    print(1)
    for i in range(R):
        for j in range(C):
            print(farm[i][j], end='')
        print()
else:
    print(0)