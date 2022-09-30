# 완전탐색: 시간초과
# def solution(n):
#     # answer = 0
#
#     arr = [[0 for _ in range(n)] for _ in range(n)]
#     answer = dfs(arr, cnt=0, answer=0, idx=(0,0))
#
#
#     return answer
#
#
#
# def dfs(arr, cnt, answer, idx):
#     n = len(arr)
#     # num = cnt
#
#     for i in range(idx[0], n):
#         for j in range(n):
#             if check(arr, (i, j)):
#                 arr[i][j] = 1
#                 num, answer = dfs(arr, cnt+1, answer, (i, j))
#                 if num == n:
#                     answer += 1
#                 arr[i][j] = 0
#                 # num -= 1
#
#     return cnt, answer
#
#
#
# def check(arr, idx):
#     i, j = idx
#     n = len(arr)
#     # 가로
#     if 1 in arr[i]:
#         return False
#     # 세로
#     for k in range(n):
#         if arr[k][j] == 1:
#             return False
#
#     # 대각선
#     for dir in [(1, -1), (1, 1), (-1, 1), (-1, -1)]:
#         # ii, jj = i+dir[0], j+dir[1]
#         ii, jj = i, j
#         while 0 <= ii < n and 0 <= jj < n:
#             if arr[ii][jj] == 1:
#                 return False
#             ii, jj = ii + dir[0], jj + dir[1]
#
#     return True


# 백트래킹
# 각 행과 열에 한개의 퀸만 존재해야하고, 대각선에 서로 위치하지 않아야한다.
# 따라서 퀸이 있는 위치를 2차원이 아닌 1차원의 행렬로 기록한다.
# 각 행에 대해 모든 열에 하나씩 퀸을 넣으며(완전 탐색), 조건에 만족하도록(백트래킹) dfs로 문제의 답을 찾는다.

def solution(n):
    row = [0] * n
    visited = [0] * n
    cnt, answer = dfs(0, 0, row, n, visited)
    return answer


def dfs(answer, cnt, row, n, visited):
    new_cnt = cnt
    if cnt == n:
        answer += 1
    else:
        # 열에 대해 퀸을 체크하기 때문에 visited도 열에 관한 방문 정보를 기록
        for i in range(n):
            if visited[i]:
                continue
            row[cnt] = i  # [cnt, i]에 퀸을 놓겠다.

            if is_vaild(row, cnt):
                visited[i] = 1
                new_cnt, answer = dfs(answer, cnt+1, row, n, visited)
                visited[i] = 0
    return new_cnt, answer


# 대각선, 같은 열에 속해있는지 체크
def is_vaild(arr, cnt):
    for i in range(cnt):
        if arr[cnt] == arr[i] or abs(cnt-i) == abs(arr[cnt]-arr[i]):
            return False
    return True







if __name__ == '__main__':
    print(solution(4))

