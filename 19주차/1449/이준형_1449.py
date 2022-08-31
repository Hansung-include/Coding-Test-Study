import sys


def solution(N, L, leaks):
    start = leaks[0]
    cnt = 1

    if len(leaks) == 1:  # 새는 곳이 하나면 테이프 한개 필요
        return 1

    for leak in leaks[1:]:  # 새는 곳이 여러개일때
        if L < leak-start+1:  # 하나의 테이프로 여러개를 막을수 있는 경우 체크
            start = leak
            cnt += 1

    return cnt

if __name__ == '__main__':
    N, L = map(int, sys.stdin.readline().split())
    leaks = list(map(int, sys.stdin.readline().split()))
    leaks = sorted(leaks)  # 정렬을 한다.
    print(solution(N, L, leaks))