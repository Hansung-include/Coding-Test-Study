def solution(n, arr1, arr2):
    answer = []
    arr1_map = [[0 for _ in range(n)] for _ in range(n)]  # 이진수 표현
    arr2_map = [[0 for _ in range(n)] for _ in range(n)]  # 이진수 표현

    for arr_i, arr in enumerate([arr1, arr2]):
        if arr_i == 0:
            arr_map = arr1_map
        else:
            arr_map = arr2_map
        for row_i, row in enumerate(arr):
                i = -1  # 인덱스 제일 마지막부터 초기화
                while row:
                    arr_map[row_i][i] = row % 2
                    row //= 2
                    i -= 1

    for i in range(n):
        row = ''
        for j in range(n):
            val = "#" if arr1_map[i][j] | arr2_map[i][j] else " "  # 하나라도 벽이면 #
            row += val  # 문자열 추가
        answer.append(row)

    return answer


if __name__ == '__main__':

    n = 5
    arr1 = [9, 20, 28, 18, 11]
    arr2 = [30, 1, 21, 17, 28]
    print(solution(n, arr1, arr2))