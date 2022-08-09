/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/실패율
*/

/*
 * 풀이
 * 사용 알고리즘 : 브루트포스, 정렬
 * 단순히 모든 실패율을 다 구하고, 이를 통해 정렬해준다. 이때, 같은 실패율을 가진 사람은 순서가 유지되어야 하기에, 안정정렬을 사용한다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> ratio(N);
    int l = 0, r = 0, prev;

    sort(stages.begin(), stages.end());
    for (int i = 1; i <= N; i++) {
        prev = l;
        ratio[i - 1].first = i;

        while (stages[l] <= i) l++;

        ratio[i - 1].second = (double)(l - prev) / (stages.size() - prev);
    }
    sort(ratio.begin(), ratio.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second > b.second;
    });
    for (auto& x : ratio) answer.push_back(x.first);
    return answer;
}