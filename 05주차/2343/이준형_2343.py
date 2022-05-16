
# 42028 KB / 784 ms
# 블루레이 크기에 대해 이분탐색을 진행하면 된다. 최소는 강의 리스트중 가장 긴 시간으로, 최대는 총합으로 한다.
# 블루레이 개수가 한개라면 모든 강의를 하나에 담아야하기 때문에 최대값은 총합이 된다.
# 앞에서부터 블루레이 크기를 넘기전까지 계속 하나의 블루레이에 녹화하고, 크기가 넘어간다면 새로운 블루레이에 녹화를 한다.
# 이렇게 진행하면서 블루레이 개수가 초과 되어버린다면 블루레이 크기를 조절한다.

import sys

N, M = map(int, sys.stdin.readline().split())
n_list = list(map(int, sys.stdin.readline().rstrip().split()))

start = max(n_list)
end = sum(n_list)

while start <= end:
    using_blueray_num = 1  # 사용중인 블루레이 개수
    used_blueray_size = 0  # 녹화된 블루레이의 크기
    possible = True  # 문제 조건에 만족하는지 여부

    size = (start+end)//2  # 블루레이 크기

    for n in n_list:  # 하나씩 돌면서 체크
        if n > size:  # 블루레이 크기보다 강의 시간이 더 클 경우
            possible = False
            break

        if size >= used_blueray_size + n:
            used_blueray_size += n
        else:
            used_blueray_size = n
            using_blueray_num += 1

        if using_blueray_num > M:  # 블루레이 개수를 초과할 경우
            possible = False
            break

    if possible:  # 블루레이 크기를 조절한다
        end = size - 1  # 최소한으로 블루레이 크기를 구해야하기 때문에 end 값을 조절한다.
    else:
        start = size + 1  # 블루레이 크기를 키워야하기에 start 값을 조절한다.

print(start)
