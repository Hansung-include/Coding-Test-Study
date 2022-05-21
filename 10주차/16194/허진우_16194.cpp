/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/16194
*/

/*
 * 풀이
 * 사용 알고리즘 : dp
 * 맨 처음에는 내 풀이가 dp인줄 알았지만, 다시 생각해보니 브루트포스적 접근이어서 시간초과로 틀렸다.
 * 이후 어떻게 접근할지 고민하다가 6주차의 1149번의 문제 풀이를 응용하였다.
 * dp의 접근은 하나의 문제를 작은 문제로 쪼개어 그 문제로 큰 문제를 푸는 것이다.
 * i개의 카드를 구매하는 문제는 i-1개를 구매하는 문제로 쪼갤수 있다.
 * 이를 응용하여 n개의 카드를 구매(n < i)할 때의 최소가격을 찾아내고, 이를 n + 1개에서의 최소가격에 반영한다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> P;
// vector<vector<int>> memo;
int n;

void input() {
    cin >> n;
    // memo.resize(n + 1);
    // for(int i = 1; i <= n; i++) memo[i].resize(n + 1, 0);
    P.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> P[i];
}

// int dp(int x, int card_cnt) {
//     if (card_cnt == n) return P[x];
//     fill(memo.begin(), memo.end(), 0);
//     int cost = 2e4;
//     for (int i = 1; i <= n - card_cnt; i++) {
//         if (!memo[i][card_cnt + i]) {
//             memo[i][card_cnt + i] = dp(i, card_cnt+ i);
//         }
//         cost = min(cost, P[x] + memo[i][card_cnt + i]);
//     }
//     return cost;
// }
// void sol() {
//     int min_pay = 2e9;
//     for (int i = 1; i <= n; i++) {
//         min_pay = min(min_pay, dp(i, i));
//     }
//     cout << min_pay;
// }

void sol() {
    vector<int> dp(n + 1, 1e4 + 1); 
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j] + P[j]);
        }
    }
    cout << dp[n];
}

#define CASEN 7
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef BOJ // 테케 검증용 조건부 컴파일
    for (int i = 0; i < CASEN; i++) {
        input();
        sol();
        cout << '\n';
        P.clear();
    }
    #endif
    #ifdef BOJ
        input();
        sol();
    #endif
}