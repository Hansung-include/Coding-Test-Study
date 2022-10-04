/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/문자열 내 마음대로 정렬하기
*/

/*
 * 풀이
 * 사용 알고리즘: 정렬
 * 단순한 정렬문제. idx의 문자를 비교하도록 하되, 같으면 사전순 정렬을 해야하는 것에 유의하자.
*/

#include <bits/stdc++.h>
using namespace std;

int idx;

bool comp(const string& a, const string& b) {
    return a[idx] != b[idx] ? a[idx] < b[idx] : a < b;
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}