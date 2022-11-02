import sys

# 완전 탐색
# 다른 도시로 갈수만 있다면 이동하면서(모든 경우의 수 체크)
# 최소의 비용을 찾는다.

def dfs(cost, visit, start, total_cost, first, min_cost):
    # start: 출발 도시, total_cost: 현재 이동하면서 소비한 비용, first: 처음에 출발한 도시 번호, min_cost: 최소 비용
    if sum(visit) == len(visit):
        if cost[start][first]:  # 다시 원래의 도시로 돌아올 수 있는 경우
            return total_cost+cost[start][first]
        return 0  # 갈 수 없다면 0을 리턴

    for i in range(len(visit)):
        if visit[i] or cost[start][i] == 0:  # 갈 수 없는 경우
            continue

        visit[i] = 1
        dfs_cost = dfs(cost, visit, i, total_cost+cost[start][i], first, min_cost)
        if dfs_cost:  # 갈 수 없는 경우 제외
            min_cost = min(min_cost, dfs_cost)
        visit[i] = 0

    return min_cost


n = int(sys.stdin.readline())
cost = []
visit = [0 for _ in range(n)]
answer = sys.maxsize

for _ in range(n):
    cost.append(list(map(int, sys.stdin.readline().split())))

for i in range(n):
    visit[i] = 1
    answer = min(answer, dfs(cost, visit, i, 0, i, answer))
    visit[i] = 0

print(answer)