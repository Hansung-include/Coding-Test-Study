/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/3 x n 타일링
*/

/*
 * 풀이
 * 사용 알고리즘: dp
 * n = 2일때 가능한 경우 = 3
 * n = 4일때 가능한 경우 = (n = 2일때 가능한 경우) * (n = 2일때 가능한 경우) + (n = 4에서의 특별한 경우)2 = 11
 * n = 6일때 가능한 경우 = (n = 4일때 가능한 경우) * (n = 2일때 가능한 경우) + (n = 2일때 가능한 경우) * (n = 4의 특별한 경우)2 + (n = 6일때 특별한 경우)2 = 41
 * ....가 반복된다.
 * 이를 점화식으로 세우면 N(은 6이상의 짝수)에 대해 다음과 같은 식이 유도된다.
 * f(N) = f(N - 2) * 3 + f(N - 4) * 2 + f(N - 6) * 2 +...+ 2
 * 숫자가 커질 수 있기 때문에 모듈러 연산과 자료형에 주의한다.
*/

#include <bits/stdc++.h>
#define MOD (int)(1e9+7)
using namespace std;

int solution(int n) {
    if (n % 2 == 1) return 0;

     vector<long long> dp = {0, 3, 11}; // 0, 2, 4, 6
    if (n / 2 <= 2) return dp[n / 2];
    else {
        for(int i = 2; i < n / 2; i++) {
            long long temp = (3 * dp[i] + 2) % MOD;
            for (int j = i - 1; j >= 1; j--) {
                temp += (2 * dp[j]) % MOD;
                temp %= MOD;
            }
            temp %= MOD;
            dp.push_back((int)temp);
        }
    }
    return dp[n / 2];
}