import sys
# 완전탐색
# 배열 하나 하나를 모두 바꾼다.
# 그때 차이 값을 구하면서 최대의 값을 구한다.

def dfs(arr, n, d, start_idx):
    ans = d

    for i in range(start_idx, n-1):  # i: 바꿀 대상
        for j in range(i, n):  # j: 바뀌는 대상
            if i != 0:
                left_d = abs(arr[i]-arr[i-1])  # 바꾸기 전의 i번째와 i-1번째의 차이를 우선 구해논다.

            arr[i], arr[j] = arr[j], arr[i]  # 배열의 i번째와, j번째를 바꾼다.
            if i != 0:
                change_ans = dfs(arr, n, d - left_d + abs(arr[i]-arr[i-1]) + abs(arr[i]-arr[i+1]), i+1)  # 바뀐후 i와 i-1, i+1번째의 차이를 다시 구한다
            else:
                change_ans = dfs(arr, n, d + abs(arr[i]-arr[i+1]), i + 1)

            arr[i], arr[j] = arr[j], arr[i]  # 다시 원래대로 바꾼다, 바꿨을때와 바꾸지 않았을때를 모두 확인하기 위해
            if i != 0:
                no_ch_d = d + abs(arr[i]-arr[i+1]) + abs(arr[i]-arr[i-1]) - left_d  # 바꾸지 않았을때의 차이를 구한다.
            else:
                no_ch_d = d + abs(arr[i]-arr[i+1])

            ans = max(ans, change_ans, no_ch_d)  # 큰 값을 구하기 위해 max 값으로 리턴한다.

    return ans


n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split(' ')))
print(dfs(arr, n, 0, 0))

