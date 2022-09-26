/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/로또의 최고 순위와 최저 순위
*/

/*
 * 풀이
 * 사용 알고리즘: 구현, 수학
 * 몇개의 숫자가 지워져 있기 때문에, 최저 순위는 지워지지 않은 나머지 숫자중에서 정답과 일치하는 숫자의 개수로 따지면 될 것이고, 최고 순위는 여기에  0의 개수를 더해주면 될 것이다.
 * 이 때, 같은 숫자가 아예 없을 때, 그리고 0도 없고 같은 숫자도 존재하지 않는 경우의 예외 처리를 해주어야 한다.
*/

#include <bits/stdc++.h>
using namespace std;

int same_cnt(const vector<int>& lotto, const vector<int> win) {
    int cnt = 0;
    for(int i = 0; i < lotto.size(); i++) {
        if (lotto[i] == 0) continue;
        for(int j = 0; j < win.size(); j++) {
            if (lotto[i] == win[j]) cnt++;
        }
    }
    return cnt;
}

int zero_cnt(const vector<int>& lotto) {
    int cnt = 0;
    for(int i = 0; i < lotto.size(); i++) {
        if (lotto[i] == 0) cnt++;
    }
    return cnt;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same = same_cnt(lottos, win_nums);
    int zero = zero_cnt(lottos);
    
    answer.push_back(7 - (same + zero ? same + zero : 1)); // 모두 다른 경우를 위한 조건식
    answer.push_back(7 - (same ? same : 1)); // 같은것이 아예 없을 때의 조건식

    return answer;
}