/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/n^2 배열 자르기
*/

/*
 * 풀이
 * 사용 알고리즘: 수학
 * i행 j열의 숫자는 i + 1과 j + 1중 큰 숫자로 결정된다.
 * 1차원 배열로 변환한 인덱스값을 다시 2차원 배열의 행, 열 값으로 변환하고, 위 과정을 거친다.
*/

#include <bits/stdc++.h>
using namespace std;

int slice_array_idx(long long idx, int n) {
    int quotient = idx / n + 1; // 몫
    int remainder = idx % n + 1; // 나머지
    
    return quotient > remainder ? quotient : remainder;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(auto i = left; i <= right; i++) answer.push_back(slice_array_idx(i, n));
    return answer;
}