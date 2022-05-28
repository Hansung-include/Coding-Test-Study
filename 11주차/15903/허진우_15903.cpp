/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/16194
*/

/*
 * 풀이
 * 사용 알고리즘 : 그리디
 * 랜덤으로 고른 두 카드의 합으로 덮어쓰는 작업을 m번 했을 때의 최솟값이기 때문에 
 * 가장 작은 두 수의 합으로 덮어 쓰고, 다시 가장 작은 수의 합으로 덮어 쓰는 작업을 반복하면 최솟값이 될 것이다.
 * 또한, 가장 작은 두 수를 구할 때, 계속해서 정렬하는 것도 방법이겠지만, 우선순위 큐를 통해 알아서 맨 위의 두 값이 가장 작은 값이 되도록 한다.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void input() {
    int input;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> input;
        pq.push(input);
    }
}

void sol() {
    int a, b;
    int result = 0;
    for(int i = 0; i < m; i++) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    while(!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}