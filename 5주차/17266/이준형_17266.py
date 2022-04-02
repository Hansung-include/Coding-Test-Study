import sys
import math

# solution1 : 이분 탐색 알고리즘 X (아래 이분탐색보다 빠르지만 메모리는 더 많이 든다.)
# 시작점과 첫번째 가로등 거리, 가로등간 사이의 거리, 마지막 가로등과 끝점 사이의 거리중 max 값을 찾는다
# 44008 KB, 132 ms

def solution1(N, M, x_list):
    max_x_list_diff = 0
    for i in range(M-1):
        diff = x_list[i+1] - x_list[i]
        max_x_list_diff = max(diff, max_x_list_diff)

    answer = max(int(math.ceil(max_x_list_diff/2)), x_list[0], N-x_list[-1])
    print(answer)


# 이분탐색 풀이
# 시작점과 끝점의 중심점에 포인터를 두고 시작점과 끝점의 중심을 높이로 가정한다.
# 두 점이 교차하면 탐색을 종료한다.
# 41982 KB, 384 ms

def bianary_search(N, M, x_list):
    left = 1  # 시작점
    right = N  # 끝점
    answer = sys.maxsize

    while left <= right:
        height = (left + right) // 2  # 중심
        if (left + right) % 2 != 0:  # 홀수일경우 1을 더해줌.(반올림)
            height += 1

        if x_list[0] > height:  # 시작점과 첫번째 가로등 거리 체크
            flag = False  # flag=false : 가로등 높이가 불가한 경우
        else:
            flag = True  # flag=true : 가로등 높이가 가능한 경우

        for i in range(M-1):  # 가로등 끼리의 거리 체크
            if x_list[i+1] - x_list[i] > 2*height:
                flag = False
                break

        if N - x_list[-1] > height:  # 마지막 가로등과 끝점 사이의 거리 체크
            flag = False

        if flag:
            right = height - 1
            answer = height
        else:
            left = height + 1

    print(answer)


if __name__ == '__main__':
    N = int(sys.stdin.readline())
    M = int(sys.stdin.readline())
    x_list = list(map(int, sys.stdin.readline().rstrip().split()))

    # solution1(N, M, x_list)
    bianary_search(N, M, x_list)