/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/3273
*/

/*
 * 풀이
 * 사용 알고리즘 : 투 포인터
 * 배열의 길이가 10만이고, 브루트포스를 통해 두수의 합을 구하면 제한시간 1초를 넘어가게 된다. (O(n^2)이니까).
 * 투포인터 알고리즘을 통해 O(n)의 시간 복잡도로 해결한다.
 * 들어온 값을 오름차순 정렬하고, 하나는 맨 처음부터, 다른 하나는 맨 오른쪽을 가르키며, 이 둘이 같아질때까지 이동시키면서
 * 두 수의 합이 r(코드상에서는 target)인 경우를 모두 센다.
*/


#include <bits/stdc++.h>
using namespace std;

int n, target;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n);
    for(int& x : v) cin >> x;
    cin >> target;
    sort(v.begin(), v.end());
}

void sol() {
    int cnt = 0, sum = 0, lo = 0, hi = n - 1;
    while(lo < hi) {
        sum = v[lo] + v[hi];
        if (sum > target) hi--;
        else if (sum < target) lo++;
        else {
            cnt++;
            hi--;
            lo++;
        }
    }
    cout << cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}