/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/키패드 누르기
 */

/*
 * 풀이
 * 사용 알고리즘 : 수학
 * 처음에는 인접행렬로 그래프를 작성하고, 최단거리 알고리즘을 사용해야하나 했는데, 이를 의도한 문제는 아닌 것 같았다.
 * *, 0, #을 각각 10, 11, 12로 생각해보니까, 거리를 구하는 방법이 떠올랐다.
 * 두 번호간의 거리는, (두 번호의 y축방향 차이) + (두 번호의 x축방향 차이)로 생각할 수 있다. 이때의 y축은 3으로 나눈 몫이 될 것이고, x축은 3으로 나눈 나머지가 될 것이다.
 * 그러면 현재의 손가락 위치와, 누르고자 하는 버튼의 차이를 구하고, 각각 몫값과 나머지값을 합하면 될 것 같았다.
*/

#include <bits/stdc++.h>
using namespace std;

int rfing, lfing;

int dist(int finger, int target) {
    int temp = abs(finger-target);
    return (temp / 3) + (temp % 3);
}

void make_ans(string& answer, int is_left, int target) {
    // left == 1이면 왼손, 0이면 오른손
    if (is_left) {
        answer += "L";
        lfing = target;
    } else {
        answer += "R";
        rfing = target;
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    rfing = 12; // "#"
    lfing = 10; // "*"
    for (int num : numbers) {
        if (num == 0) num = 11;
        
        if (num % 3 == 0) make_ans(answer, 0, num);
        else if (num % 3 == 1) make_ans(answer, 1, num);
        else if (num % 3 == 2 ) {
            int right_dist = dist(rfing, num);
            int left_dist = dist(lfing, num);

            if (right_dist > left_dist) make_ans(answer, 1, num);
            else if (right_dist < left_dist) make_ans(answer, 0, num);
            else {
                if (hand == "right") make_ans(answer, 0, num);
                else make_ans(answer, 1, num);
            }
        }
    }
    return answer;
}