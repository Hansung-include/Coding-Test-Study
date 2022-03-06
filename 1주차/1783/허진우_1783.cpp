/*
 * 이름: 허진우
 * 언어: C++17
 * 문제: 백준/1783
*/

#include <bits/stdc++.h>
using namespace std;

int main () {
    // fast i/o
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = 세로, m = 가로
    
    cin >> n >> m;
    
    /*
    조건 분기
     * 1. 세로가 1 -> 움직이지 못하므로 1
     * 2. 세로가 2 -> 최대 4칸
     * 3. 세로는 3 이상, 가로가 7보다 작음 -> 최대 4칸
     * 4. 세로는 3 이상, 가로가 7이상 -> 가로 - 2
    */
    if (n == 1) cout << 1;
    else if (n == 2) cout << min(4, (m + 1) / 2);
    else if (m < 7) cout << min(4, m);
    else cout << m - 2;
}


