def solution(board, moves):
    answer = 0
    doll_idx = [0 for _ in range(len(board[0]))]  # 1, 2, 3, 4,, 번에 있는 가장 높게 위치한 인형의 index 를 저장
    for i in range(len(board[0])):  # 1, 2, 3, 4번  for 문
        for j in range(len(board)):  # height for 문
            if board[j][i]:
                doll_idx[i] = j
                break

    basket = []  # 바구니
    for m in moves:  # 하나씩 인형을 뽑으면서
        idx = m - 1  # idx 조정
        doll = board[doll_idx[idx]][idx]  # 인형의 고유 번호
        board[doll_idx[idx]][idx] = 0  # 뽑았으니 없다고 표시
        if doll_idx[idx]+1 < len(board):  # 인형을 뽑았으니 한칸 아래인 idx 로 저장
            doll_idx[idx] += 1

        if basket and basket[-1] == doll:  # 동일한 인형이 저장되었을경우
            basket = basket[:-1]  # 인형 두개는 터뜨려진다
            answer += 2  # 정답 2개 추가
        elif doll == 0:  # 인형이 없다면 패스
            continue
        else:
            basket.append(doll)
    return answer

if __name__ == '__main__':
    board = [[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]]
    moves = [1,5,3,5,1,2,1,4]
    answer = solution(board, moves)
    print(answer)