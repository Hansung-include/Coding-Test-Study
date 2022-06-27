/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/7795
*/

/*
 * 풀이
 * 사용 알고리즘 : 이진 탐색
 * 전형적인 이진탐색 문제이다. 브루트포스로 접근하면 시간복잡도가 O(nm)이고, n, m <= 20000이기 때문에 최대 4억번의 연산이 발생한다.
 * 또한 입력받은 데이터를 정렬도 해야하기 때문에, 브루트포스로는 당연히 통과가 불가능하다.
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int nA, nB;
vector<int> a, b;

void input() {
    cin >> nA >> nB;
    a.clear(); b.clear();
    a.resize(nA); b.resize(nB);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void sol() {
    int result = 0;
    for(int& x : a) {
        result += lower_bound(b.begin(), b.end(), x) - b.begin();
    }
    cout << result << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        input();
        sol();
    }
}