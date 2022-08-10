/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/2193
*/

/*
 * 풀이
 * 사용 알고리즘: dp
 * 3이상의 이친수는 모두 10으로 시작해야한다.
 * n = 3일때의 이친수는 100, 101으로 2개인데, 앞에 10은 떼보면 0, 1만 남는데, 이를 생각해보니 각각 n = 2일때의 끝의 1자리, 그리고 n = 1일때의 끝의 한자리였다.
 * n = 4의 경우 1000, 1001, 1010이고, 떼보면 00, 01, 10이 남는다. 이는 또 n = 3일때의 끝 두자리, n = 2일때의 끝 두자리다.
 * n = 6정도까지 써보니까 이 규칙이 맞다고 생각했고, 일반화를 진행해보니 n일때의 경우  n - 1일때의 개수 + n - 2일때의 개수가 된다. 즉 피보나치 수열이 된다
*/

#include <bits/stdc++.h>
using namespace std;

uint64_t sol(int n) {
    uint64_t dp[91] = {0, 1, 1};
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cout << sol(n);
}