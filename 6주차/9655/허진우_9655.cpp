#include <bits/stdc++.h>
using namespace std;

/*
 * 풀이
 * 결국 가져가는 돌의 개수는 홀수개이기 때문에, 3개를 가져가든 1개를 가져가든 상관이 없다
 * 돌의 개수가 홀수개라면, 어떻게 해도 상근이가 이기고, 짝수개라면 어떻게 해도 창영이가 이기게 된다.
*/

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    if (n & 1) cout << "SK";
    else cout << "CY";
}