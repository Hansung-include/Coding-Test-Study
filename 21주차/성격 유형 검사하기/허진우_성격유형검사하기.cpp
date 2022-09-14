/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/성격 유형 검사하기
*/

/*
 * 풀이
 * 사용 알고리즘 : 구현
 * 단순한 구현 문제이다. map을 통해 모든 성격 유형에 대해 점수를 매기고, 더 큰 점수를 가진 성격유형을 붙여주었다.
*/

#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    // 변수 선언 및 초기화
    string answer = "";
    array<char, 8> category = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    map<char, int> personality_score;

    for(auto& elem : category) personality_score.insert({elem, 0});
    
    // 점수 부여
    for(int i = 0; i < survey.size(); i++) {
        string& item = survey[i]; // 성격 질문
        int choice = choices[i]; // 점수

            if(choice > 4) { // 4점 초과. 뒷 성격에 점수 부여
                personality_score[item[1]] += choice - 4;
            }
            else if (choice < 4) { // 4점 미만. 앞 성격에 점수 부여
                personality_score[item[0]] += 4 - choice;
            }
    }

    // 성격 유형 부여
    for(int i = 0; i < 8; i += 2) {
        char first = category[i];
        char second = category[i + 1];
        int first_score = personality_score[first];
        int second_score = personality_score[second];

        if(first_score != second_score) answer += first_score > second_score ? first : second;
        else answer += first < second ? first : second;
    }


    return answer;
}