/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/16401
*/

/*
 * 풀이
 * 시용 알고리즘: 이분탐색
 * 과자의 수와 길이 모두 많이 크고, 과자의 길이 x에 대해 각 과자를 모두 탐색해야하기 때문에 이분탐색이 적절하다.
*/

#include <bits/stdc++.h>
using namespace std;

int child, snackCnt;
vector<int> snack;

void input() {
    cin >> child >> snackCnt;
    snack.resize(snackCnt);
    for (int& x : snack) cin >> x;
    sort(snack.begin(), snack.end());
}

int checkCnt(int x) {
    int cnt = 0;
    for (int len : snack) cnt += len / x;
    return cnt;
}

void sol() {
    int st = 1, ed = snack[snackCnt - 1];
    int mid, result = 0;
    while (st <= ed) {
        mid = (st + ed) / 2;

        if (child <= checkCnt(mid)) {
            st = mid + 1;
            result = mid;
        }
        else {
            ed = mid - 1;
        }
    }
    cout << result;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}