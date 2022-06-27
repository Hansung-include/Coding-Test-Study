
# 문제 : https://www.acmicpc.net/problem/7795

# A 리스트를 하나씩 보면서 B 리스트는 포인터를 하나 달아서 두 개를 각각 비교해서 개수를 체크합니다.
import sys


def solution(a_list, b_list):
    answer = 0
    a_list = sorted(a_list)
    b_list = sorted(b_list)

    b_pos = 0
    for a in a_list:
        # a 요소가 중복 + b 보다 작을때
        if a <= b_list[b_pos]:
            answer += b_pos
            continue

        while a > b_list[b_pos]:
            if b_pos < len(b_list)-1:
                b_pos += 1
            # 인덱스 범위 초과할 경우
            else:
                break

        if a <= b_list[b_pos]:
            answer += b_pos
        else:
            answer += b_pos+1

    return answer


if __name__ == '__main__':
    T = int(sys.stdin.readline())
    answer = []
    for _ in range(T):
        a_len, b_len = map(int, sys.stdin.readline().split())
        a_list = list(map(int, sys.stdin.readline().split()))
        b_list = list(map(int, sys.stdin.readline().split()))
        answer.append(solution(a_list, b_list))

    for a in answer:
        print(a)
