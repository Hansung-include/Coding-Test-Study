/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/6236
*/

/*
 * 풀이 : 이진 탐색
 * 순차탐색으로 진행한다면 분명히 시간초과가 터질 것이기 때문에, 이진탐색으로 접근해야 한다.
 * 순차탐색의 경우, 탐색의 시작은 들어온 금액의 최댓값, 끝은 10억 (N = 10만, M = 1, 모든 금액이 1만일때)이고, 각 가격에서 10만개의 데이터를 계속 돌아야 하기 때문이다.
*/

#include <bits/stdc++.h>
using namespace std;

int m, n;
int st = -1, ed = 1e9;
vector<int> v;

void input() {
    cin >> n >> m;
    v.resize(n);
    for(int& x : v) {
        cin >> x;
        st = max(x, st);
    }
}

bool check(int money) {
    int hand = money;
    int cnt = 1;

    for(int x : v) {
        if (money < x) return false;

        if (hand >= x) hand -= x;
        else {
            cnt++;
            hand = money - x;
        }
    }
    return cnt <= m;
}

void sol() {
    int mid;
    int result;
    while (st <= ed) {
        mid = (st + ed) / 2;

        if (check(mid)) {
            ed = mid - 1;
            result = mid;
        }
        else {
            st = mid + 1;
        }
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}