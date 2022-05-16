/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/1697
*/
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

/*
 * 풀이
 * 최단 거리를 구해야 하기 때문에 입력받은 시작지점으로부터 -1, 1, x2인 노드로 순차적으로 방문한다.
 * bfs를 통해 가장 먼저 동생의 위치에 도착한다면, 그것이 최소이동횟수이다.
 * dfs를 통해 접근한다면, 어디서 멈춰야 할 지 정하기가 힘들 것 같았다. 적절한 경계를 찾기 힘들기 때문이다.
 * dfs로 접근했을 때, 제일 큰 값을 MAX로 잡는 경우, segmentation fault, 적당하다고 판단한 2 * (동생의 위치)의 경우 제대로 작동하지 않았다. (설계의 문제일 수도 있긴 하다.)
*/

void solution(int start, int target, int time) {
    int ans;
    bool visited[MAX] = {false, };
    queue<pair<int, int>> q; // pair -> (location, time)
    q.push(make_pair(start, 0));
    visited[start] = true;

    while(!q.empty()) {
        int loc = q.front().first;
        int t = q.front().second;
        q.pop();

        if (loc == target) {
            ans = t;
            break;
        }

        if (loc + 1 < MAX && !visited[loc + 1]) {
            q.push(make_pair(loc + 1, t + 1));
            visited[loc + 1] = true;
        }

        if (loc * 2 < MAX && !visited[loc * 2]) {
            q.push(make_pair(loc * 2, t + 1));
            visited[loc * 2] = true;
        }
        
        if (loc - 1 >= 0 && !visited[loc - 1]) {
            q.push(make_pair(loc - 1, t + 1));
            visited[loc - 1] = true;
        }
    }
    cout << ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int start, target;
    cin >> start >> target;
    solution(start, target, 0);
}