import sys
N = int(sys.stdin.readline())

# 55388kb / 572ms
solve_1 = 0
solve_2 = []
solve_3 = {}
solve_4 = 0

# solve 3
# 딕셔너리(정수, 해당 정수가 나타난 개수) 로 저장을 함.
# 최빈값을 찾은후에 최빈값에 해당하는 정수가 여러개면 정렬하여 두번째로 작은 값을 출력

for _ in range(N):
    n = int(sys.stdin.readline())
    solve_1 += n
    solve_2.append(n)
    if n in solve_3:
        solve_3[n] += 1
    else:
        solve_3[n] = 1

# solve 1
print(int(round(solve_1/N, 0)))

# solve 2
solve_2 = sorted(solve_2)
print(solve_2[N//2])

# solve 3
max_cnt = 0
max_n_list = []
for n, cnt in solve_3.items():
    if max_cnt < cnt:
        max_cnt = cnt
        max_n_list = [n]
    elif max_cnt == cnt:
        max_n_list.append(n)
if len(max_n_list) > 1:
    max_n_list = sorted(max_n_list)
    print(max_n_list[1])
else:
    print(max_n_list[0])

# solve_4
solve_4 = solve_2[-1] - solve_2[0]
print(solve_4)