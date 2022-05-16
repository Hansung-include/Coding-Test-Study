/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/2217
*/

/*
 * 풀이
 * 전체 로프에서 n개를 사용했을때의 최대 중량은 (n개의 로프중 제일 짧은 길이) * n이다.
 * 제일 긴 로프부터 1, 2, 3... 의 번호를 부여했을 때, 로프의 길이 * 부여밭은 번호가, 각 n개에서의 최대 중량이다.
 * 오름차순 정렬을 한 후에, 이 과정을 거치면 된다.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> rope;

void input() {
    int temp;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        rope.push_back(temp);
    }
    sort(rope.begin(), rope.end(), greater<>());
}

void sol() {
    for(int i = 0; i < n; i++) {
        rope[i] *= i + 1;
    }
    cout << *max_element(rope.begin(), rope.end());
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}