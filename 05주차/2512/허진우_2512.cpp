/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/2512
*/

/*
 * 풀이:
 * 최소 예산 1, 최대 예산을 입력받은 요청 예산중 최댓값으로 한다.
 * 이 사이에서 이진 탐색을 진행하여 조건을 만족하는 최댓값을 찾는다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
int st = 1, ed = -1;

void input() {
    ed = -1;
    cin >> n;
    v.resize(n);
    for(int& x : v) {
        cin >> x;
        ed = max(ed, x);
    }
    cin >> m;
}

inline int budget(int maximum) {
    int result = 0;
    for(int& x : v) {
        if (x <= maximum) result += x;
        else result += maximum;
    }
    return result;
}

void solution() {
    int mid;
    int result = 0;

    while(st <= ed) {
        mid = (st + ed) / 2.;
        if (budget(mid) > m) {
            ed = mid - 1;
        }
        else {
            result = mid;
            st = mid + 1;
        }
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
}