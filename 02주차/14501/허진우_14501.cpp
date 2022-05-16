/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/14501
*/

#include <bits/stdc++.h>
using namespace std;

int N;
int* T; // Ti
int* P; // Pi
int* dp; // dp 식

void input(){
    cin >> N;
    T = new int[N + 1];
    P = new int[N + 1];
    dp = new int[N + 1];
    fill(dp, dp + N + 1, 0); // 초기화
    for(int i = 0; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
}

void solution(){
    int max_pay = 0; // 최댓값을 저장하는 변수
    for(int i = 0; i <= N; i++) {
        dp[i] = max(max_pay, dp[i]);
        // 잘못된 메모리 참조를 하지 않기 위한 조건
        if (T[i] + i <= N) {
            dp[T[i] + i] = max(dp[T[i] + i], P[i] + dp[i]);
        }
        max_pay = max(max_pay, dp[i]);
    }
    cout << max_pay;
}

int main () {
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
     * 생각
     * 브루트포스로 최대 이익을 계산한다. 
     * dp라는 배열에 i일에 진행하는 상담을 했을 때에 받을 금액을 i + T[i]번째에 저장한다.
     * 이렇게 해서 제일 큰 금액을 출력
    */

    input();
    solution();
}