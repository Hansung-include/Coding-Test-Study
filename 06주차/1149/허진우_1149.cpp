#include <bits/stdc++.h>
using namespace std;

/*
 * 풀이
 * i번째의 집을 칠하기 위해서는, i번째와 다른 색으로 칠했을때의 i - 1번째 집의 비용 + i번째 색칠 비용의 값과 같다.
 * 이 둘의 최솟값을 저장하며, 반복문을 돌고, 맨 마지막에 도달했을 때, 비용의 최솟값을 찾아준다.
*/

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int rgb_cost[3];
    int house[1001][3] = {0, 0, 0, };
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) cin >> rgb_cost[j];
        for(int j = 0; j < 3; j++) {
            house[i][j] = min(house[i - 1][(j + 1) % 3], house[i - 1][(j + 2) % 3]) + rgb_cost[j];
        }
    }
    cout << min(min(house[n][0], house[n][1]), house[n][2]);
}