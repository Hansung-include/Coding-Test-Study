/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/16956
*/

/*
 * 풀이
 * 울타리의 최소 개수가 없다 -> 맘껏 써도 된다.
 * 그래프의 맨 처음부터 차례대로 순회하면서, 늑대가 발견되고, 상하좌우에 양이 있다면, 그 즉시 실패처리를 한다.
 * 없다면 늑대의 상하좌우에 울타리를 친다. 울타리의 최소 개수를 묻는 것이 아닌, 양이 먹히지만 않으면 된다.
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int r, c;
vector<string> board;

void input() {
    cin >> r >> c;
    board.resize(r);

    for(auto& x : board) {
        cin >> x;
    }
}

void solution() {
    bool flag = true;
    int nx;
    int ny;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    for(int y = 0; y < r; y++) {
        for(int x = 0; x < c; x++) {
            if(board[y][x] == 'W') {
                for(int i = 0; i < 4; i++) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if(nx >= 0 && nx < c && ny >= 0 && ny < r) {
                        if(board[ny][nx] == 'S') {
                            flag = false;
                            goto END;
                        }
                        else {
                            if (board[ny][nx] == '.') board[ny][nx] = 'D';
                        }
                    }
                }
            }
        }
    }
END:
    cout << flag << endl;
    if(flag) {
        for(const auto& x : board) {
            cout << x << endl;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
}