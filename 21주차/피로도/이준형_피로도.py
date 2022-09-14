# 완전탐색, dfs
# 해당 던전 리스트를 정렬하고 푸려고(그리디) 접근했으나, 중간에 섞이게 되면 문제에서 요구하는 최대치의 답이 나오질 않을것 같아서
# 완전탐색으로 풀이함.
# 어떤 던전부터 돌아야 할지를 몰라서 각각 던전을 처음부터 돌면서 체크한다.

def solution(k, dungeons):
    visited = [False for _ in range(len(dungeons))]  # 방문했는지 저장하는 변수
    cnt = 0  # 던전을 돈 횟수
    answer = dfs(dungeons, k, visited, cnt)  # dfs로 풀이
    return answer


def dfs(dungeons, k, visited, cnt):
    answer = cnt
    for i, dungeon in enumerate(dungeons):  # 던전을 모두 돌면서
        if visited[i]:  # 방문했던 경우
            continue  # 패스
        if k >= dungeon[0]:  # 던전 최소 체력 이상일 경우
            visited[i] = True  # 방문했다는 표시 해주고
            answer = max(answer, dfs(dungeons, k-dungeon[1], visited, cnt+1))  # 최대의 값을 저장하기 위한 max로 answer 업데이트
            visited[i] = False  # 방문을 다시 하지 않고 다른 던전을 방문하자(완전탐색)

    return answer


if __name__ == '__main__':
    print(solution(80, [[80,20],[50,40],[30,10]]))
    print(solution(40, [[40, 20], [10, 10], [10, 10], [10, 10], [10, 10]]))