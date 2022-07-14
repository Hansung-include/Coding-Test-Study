/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/문자열 압축
*/

/*
 * 풀이
 * 사용 알고리즘 : 문자열, 브루트포스
 * 1개 단위부터 시작하여 s의 절반길이만큼의 단위로 자를때 압축된 문자열의 길이들의 최소값을 구한다.
 * s가 한글자일때 에러가 났었는데, 글자가 한글자라면 반복문을 돌지 않고 바로 answer값을 반환하는데, 이때 최솟값을 구해야 하기 때문에 answer에 담긴 큰 수가 반환되었다.
 * 따라서 s가 한글자일때는 예외로 처리해야 한다.
*/

#include <bits/stdc++.h>
using namespace std;

inline bool equal(string& str, string& pattern, int start) {
    for (int i = 0; i < pattern.size(); i++)
        if (str[start + i] != pattern[i]) return false;
    return true;
}

int solution(string s) {
    if (s.length() == 1) return 1;
    int answer = 1001;
    int cnt;
    string compression_str;
    string pattern;
    for (int pattern_len = 1; pattern_len <= s.length() / 2; pattern_len++) { // 패턴 길이 설정
        compression_str = "";
        for (int j = 0; j < s.length(); j += cnt * pattern_len) { // 비교
            cnt = 1;
            pattern = s.substr(j, pattern_len); // 패턴 생성
            for (int start = j + pattern_len; start < s.length(); start += pattern_len) { // 비교
                if (equal(s, pattern, start)) {
                    cnt++;
                }
                else break;
            }

            if (cnt != 1) compression_str += to_string(cnt) + pattern;
            else compression_str += pattern;
        }
        answer = min(answer, (int)compression_str.length());
    }
    return answer;
}