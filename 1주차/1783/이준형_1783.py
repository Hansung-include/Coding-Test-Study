import sys
# 30864 KB 68 ms
# 이름: 이준형
# 언어: python
# 문제 번호: 1783

N, M = map(int, sys.stdin.readline().split())
count = 1  # 초기 위치도 방문 개수에 포함
current_point = [1, 1]

# 직접 이동하면서 방문 횟수를 세려고 했지만 시간 초과 발생
# 따라서 이동가능한 횟수를 한번에 파악하자는 의미로 접근함
# 이동횟수가 4회 이상일 경우에 조건 만족하기 위해 조건문 수행
if N >= 3 and M >= 7:
    count += 4
    current_point[1] += 6
    limit = False
else:
    limit = True  # 이동이 모든 방법을 만족하지 못할 때

if N >= 2:
    left_x, left_y = N-current_point[0], M-current_point[1]
    # 세로의 크기가 2이상이라면 위 or 아래로 2칸, 오른쪽 1칸 움직이는게 최대로 방문 횟수를 늘릴수 있다.(그리디 적용)
    if left_x >= 2:
        possible_y = left_y  # 오른쪽 1칸
    else:
        possible_y = left_y // 2  # 오른쪽 2칸
    if limit:
        possible_y = min(possible_y, 3)  # 최대 이동 수(3)를 제한함
    count += possible_y


print(count)
