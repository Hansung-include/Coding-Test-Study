/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/11057
*/

/*
 * 풀이
 * 시용 알고리즘: dp, 누적합
 * N = k일때의 경우는 N = k-1인 경우에서 제일 오른쪽에 오름차순을 유지하는 한자리 숫자를 붙인 경우이다.
 * 또한 일의 자리에 n(0 ~ 9)가 오기 위해서는, 10의 자리가 0 ~ n인 오르막 수여야 하고, 이는 N = k-1에서 0 ~ n일때의 경우의 수의 총합이다.
 * 따라서 dp배열을 맨 처음에 모두 1로 초기화하고, 계속해서 누적합 배열을 만들고, 그 배열의 총합을 구해주면 된다.
 * 이때 10,007으로 나눈 나머지를 구해야 하기에, 누적합을 구성하면서 동시에 모듈러 연산을 수행하면 된다.
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 10007

int sol(int n) {
    int dp[10];
    fill(dp, dp + 10, 1);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            dp[j + 1] += dp[j] % MOD;
            dp[j + 1] %= MOD;
        }
    }
    return accumulate(dp, dp + 10, 0) % MOD;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << sol(n);
}
