/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/2644
*/

/*
 * 풀이
 * 사용 알고리즘 : dfs, 깊이 우선 탐색
 * 찾고자 하는 노드로 가는 간선이 오로지 한개 존재하기 때문에(부모관계는 한개만 주어짐) dfs로 탐색하면서 구한 촌수가 곧 정답이 된다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int st, ed;
int ans = -1;

void input() {
    int human_cnt, loop;
    int tmp1, tmp2;
    cin >> human_cnt >> st >> ed >> loop;
    graph.resize(human_cnt + 1);
    visited.resize(human_cnt + 1);
    fill(visited.begin(), visited.end(), false);
    for(int i = 0; i < loop; i++) {
        cin >> tmp1 >> tmp2;    
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
}

void dfs(int st, int connected_cnt) {
    visited[st] = true;

    if (st == ed) {
        ans = connected_cnt;
        return;
    }

    for (int x : graph[st]) {
        if (!visited[x]) {
            dfs(x, connected_cnt + 1);
        }
    }
}

void sol() {
    dfs(st, 0);
    cout << ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}