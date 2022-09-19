def solution(n, left, right):
    answer = []
    row = left // n  # 행 idx
    col = left % n  # 열 idx

    while left <= right:
        rows = [max(row + 1, i + 1) for i in range(n)]  # row행의 수들
        start = col  # rows를 slice할 때의 start idx 정하기

        # rows를 slice할 때의 end idx 정하기
        if right >= left+n:
            end = start + n
        else:
            end = start + (right-left+1)

        # extend
        answer.extend(rows[start:end])

        row += 1  # 다음 행
        col = 0  # 열 idx
        left = row*n  # 다음 left

    return answer


if __name__ == '__main__':
    print(solution(4, 14, 14))
    print(solution(4, 7, 14))