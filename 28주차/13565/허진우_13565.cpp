/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/
*/

/*
 * 풀이
 * 시용 알고리즘: 그래프 탐색
 * 전형적인 그래프 탐색문제이다. 그래프의 맨 아래(inner side)에서부터 탐색하며 맨 위(outer side)로 가는 경로가 존재하는지 탐색한다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;

void input() {
    cin >> m >> n;
    graph.resize(m);
    string input;

    for(auto& row : graph) {
        cin >> input;
        for(char x : input) row.push_back(x - '0');
    }
}

// 41188KB / 40ms
bool dfs(int st_x, int st_y) {
    if (st_y == 0) return true;
    graph[st_y][st_x] = -1;

    bool result = false;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int next_x = st_x + dx[i];
        int next_y = st_y + dy[i];
        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
        if (graph[next_y][next_x] == 0) result = result || dfs(next_x, next_y);
    }
    return result;
}

// 6000KB / 20ms
bool bfs(int st_x) {
    queue<pair<int, int>> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    q.push({st_x, m - 1});
    graph[m - 1][st_x] = -1;

    while(!q.empty()) {
        auto [cur_x, cur_y] = q.front();
        q.pop();

        if (cur_y == 0) return true;

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            
            if (graph[next_y][next_x] == 0) {
                graph[next_y][next_x] = -1;
                q.push({next_x, next_y});
            }
        }
    }
    return false;
}

void sol() {
    for(int x = 0; x < n; x++) {
        if (graph[m - 1][x] == 0) {
            // if (bfs(x)) {
            if (dfs(x, m-1)){
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}