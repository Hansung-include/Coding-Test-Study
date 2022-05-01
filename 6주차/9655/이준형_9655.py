import sys

# dp 문제
# 3개 가져갈 수 있으면 3개를 가져가자.
# for 문을 돌리면서 하나씩 dp 값을 다 구한다.
# dp[1] = SK, dp[2] = CY, ,,,,


N = int(sys.stdin.readline())

players = ['SK', 'CY']

def sol1(N):
    get_idx_player = 1

    while N:
        if N >= 3:
            N -= 3
        else:
            N -= 1
        get_idx_player = not get_idx_player

    print(players[get_idx_player])


def dp(N):
    result = [None]
    result.append(0)
    for i in range(2, N+1):
        if i > 3:
            player = result[i-3]
        else:
            player = result[i-1]
        result.append(not player)

    print(players[result[N]])

if __name__ == '__main__':
    dp(N)