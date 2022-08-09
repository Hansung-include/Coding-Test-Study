/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/거리두기 확인하기
*/

/*
 * 풀이
 * 사용 알고리즘 : bfs
 * bfs를 사용하여, 각 응시자들을 기준으로 맨해튼 거리를 bfs로 측정한다.
 * 이때 거리가 2 이상일때는 알 필요가 없기 때문에, bfs를 끝까지 돌리는게 아니라, 거리가 2 이하일때까지만 돌린다.
*/

#include <bits/stdc++.h>
using namespace std;

int bfs(vector<string>& board, int x, int y) {
    queue<tuple<int, int, int>> q;
    bool visit[5][5] = {false};
    int dist = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    q.push({x, y, 0});
    visit[y][x] = true;

    while(!q.empty()) {
        int cur_x = get<0>(q.front());
        int cur_y = get<1>(q.front());
        int cur_dist = get<2>(q.front());
        q.pop();

        if (cur_dist < 2) {
            for (int i = 0; i < 4; i++) {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5) continue;
                if (visit[next_y][next_x]) continue;

                if (board[next_y][next_x] == 'O') {
                    q.push({next_x, next_y, cur_dist + 1});
                    visit[next_y][next_x] = true;
                }
                else if (board[next_y][next_x] == 'P') return 0;
                else continue;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int temp;

    for(auto& tcase : places) {
        temp = 1;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(tcase[i][j] == 'P') temp &= bfs(tcase, j, i);
            }
        }
        answer.push_back(temp);
    }
    return answer;
}