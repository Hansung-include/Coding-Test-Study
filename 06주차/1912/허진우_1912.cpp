#include <bits/stdc++.h>
using namespace std;
/*
 * 풀이
 * arr에 입력받고, dp에 arr를 똑같이 복사한 후에, 반복문을 돌면서 dp[i]와 dp[i - 1] + arr[i] 중 더 큰값을 dp에 저장한다
 * 그중 제일 큰 값을 찾아내어 출력하면 된다.
*/
int* arr;
int* dp;
int n;

void input() {
    cin >> n;
    arr = new int[n];
    dp = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
}

void solution() {
    int ans = *dp;
    for(int i = 1; i < n; i++) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
    delete[] arr;
    delete[] dp;
}