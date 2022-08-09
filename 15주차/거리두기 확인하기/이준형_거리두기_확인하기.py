# dfs 풀이
# 하나의 대기실안에서 대기자가 위치해 있는 위치를 리스트로 저장한다.
# 대기자의 위치에서 상하좌우를 탐색하며 빈 테이블이 있다면 한번 더 상하좌우를 탐색한다.
# (맨허튼 거리가 2가 나올때까지므로 상하좌우를 두번 탐색하는 것이다.)
def solution(places):
    answer = [1 for _ in range(len(places))]  # 1로 초기화
    for i, place in enumerate(places):  # 하나의 대기실마다
        q = []  # 대기자 리스트
        
        # 대기자 리스트 추가
        for r, row in enumerate(place):
            for c, val in enumerate(list(row)):
                if val == 'P':
                    q.append([r, c])
                    
        # 대기자의 위치에서 탐색
        while q:
            row, col = q.pop()
            for d in [(0, 1), (-1, 0), (1, 0), (0, -1)]:  # 상하좌우 탐색
                r, c = row + d[0], col + d[1]
                if r >= 5 or r < 0 or c >= 5 or c < 0:  # 범위 벗어나면 패스
                    continue

                if place[r][c] == 'P':  # 대기자끼리의 거리가 1이다 -> 거리두기 안지킴
                    answer[i] = 0
                    q = []
                    break

                elif place[r][c] == 'O':  # 비어있는 테이블이라면 한 번더 상하좌우 탐색 (거리가 2인 경우를 체크)
                    for dd in [(0, 1), (-1, 0), (1, 0), (0, -1)]:  # 상하좌우
                        rr, cc = r + dd[0], c + dd[1]

                        if row == rr and col == cc or rr >= 5 or rr < 0 or cc >= 5 or cc < 0:  # 대기자의 처음 위치로 돌아갔을때도 패스
                            continue

                        if place[rr][cc] == 'P':  # 대기자끼리의 거리가 2이다 -> 거리두기 안지킴
                            answer[i] = 0
                            q = []
                            break

    return answer


if __name__ == '__main__':
    answer = solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]])
    print(answer)