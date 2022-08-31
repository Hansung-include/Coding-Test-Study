/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/두 큐 합 같게 만들기
*/

/*
 * 풀이
 * 사용 알고리즘 : 큐, 그리디
 * 단순히 한쪽 큐의 총합이 더 큰 경우, 그 큐에서 pop하고 다른 큐에 push하면서 합이 같아질때까지 구한다.
*/

#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;
using ull = uint64_t;

int solution(vector<int> queue1, vector<int> queue2) {
    ull sum1 = accumulate(ALL(queue1), 0);
    ull sum2 = accumulate(ALL(queue2), 0);
    ull total = sum1 + sum2;
    if (total & 1) return -1; // 홀수면 어짜피 안된다. 그냥 거른다.
    
    int answer = 0;
    int len = queue1.size();
    int temp;
    deque<int> q1, q2;

    while(!queue1.empty()) {
        q1.push_front(queue1.back());
        queue1.pop_back();
    }
    while(!queue2.empty()) {
        q2.push_front(queue2.back());
        queue2.pop_back();
    }
    for(int i = 0; i < 3 * len; i++) {
        if (sum1 > sum2) {
            sum1 -= q1.front();
            sum2 += q1.front();
            temp = q1.front();
            q1.pop_front();
            q2.push_back(temp);
            answer++;
        }
        else if (sum1 < sum2) {
            sum1 += q2.front();
            sum2 -= q2.front();
            temp = q2.front();
            q1.push_back(temp);
            q2.pop_front();
            answer++;
        }
        else { // 합이 같은 경우. 끝
            return answer;
        }
    }
    return -1; // 원소 총합이 짝수이고, 어떤 경우로도 합을 같게 할 수 없는 경우.
}