import sys
# 45004 ms / 128 kb

length = int(sys.stdin.readline())
n_list = list(map(int, sys.stdin.readline().split()))
x = int(sys.stdin.readline())

answer = 0

# # 브루트 포스: 시간 초과
# for i, n in enumerate(n_list):
#     find_num = x - n
#     if i != length-1 and find_num in n_list[i+1:]:
#         answer += 1

# 정렬을 통한 방법: 시간초과
# order_dict = {n:i for i, n in enumerate(n_list)}
# sorted_list = sorted(n_list)
#
# for i, n in enumerate(sorted_list):
#     find_n = x - n
#     for j, check_n in enumerate(sorted_list[i+1:]):
#         if check_n == find_n:
#             answer += 1
#             break
#         if check_n > find_n:
#             break



# 알고리즘..? 그리디?
# dict{num : idx} 로 저장한다
# 하나씩 루프를 돌면서 find_num(x-n)이 dict 에 존재하는지 체크한다.
n_dict = {}
for i, n in enumerate(n_list):
    n_dict[n] = i

for i, n in enumerate(n_list):
    find_num = x-n
    if find_num in n_dict and i < n_dict[find_num]:
        answer += 1


print(answer)