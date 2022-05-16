/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/1021
*/

#include <bits/stdc++.h>
using namespace std;
deque<int> dq;

// n이 최대 50이기 때문에 선형탐색으로 진행해도 상관없다.
int find_index(int target){
    for(int i = 0; i < dq.size(); i++) {
        if (dq[i] == target) return i; 
    }
    return -1;
}

int main () {
    // fast i/o
    ios_base::sync_with_stdio(false);   
    cin.tie(nullptr);

    /*
     * 생각
     * 앞 뒤에서 push & pop이 발생 -> deque
     * 연산1: std::deque.pop_front()
     * 연산2: std::deque.push_back(std::deque.front()); std::deque.pop_front()
     * 연산3: std::deque.push_front(std::deque.back()); std::deque.pop_back()
    */

    vector<int> cmd;
    int n, m, idx; // idx: deque에서 어디에 위치해 있는지
    int cnt = 0; // 2, 3번연산 횟수
    
    cin >> n >> m;

    dq.resize(n);
    cmd.resize(m);
    iota(dq.begin(), dq.end(), 1); // 1 ~ n으로 채운다.

    for(int& x : cmd) cin >> x;

    for(const int& x : cmd) {
        idx = find_index(x); // 위치 찾기
        if (n / 2. > idx){ // 왼쪽에 더 가까이 있다면
            while(dq.front() != x){ // 연산2를 수행
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else { // 오른쪽에 더 가까이 있다면
            while(dq.front() != x){ // 연산 3을 수행
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        dq.pop_front();
        n--;
    }
    cout << cnt;
}