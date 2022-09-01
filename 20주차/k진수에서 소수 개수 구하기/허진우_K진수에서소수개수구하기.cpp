/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/K진수에서 소수 개수 구하기
*/

/*
 * 풀이
 * 사용 알고리즘 : 소수 판별, 문자열
 * K진수로 변환하면 숫자의 길이가 커질 수 있기 때문에 문자열로 저장하고, 0에서 모두 자른다음에 소수를 판별한다.
 * 이때, K진수로 변환했을 때, int의 범위를 벗어날 수 있기 때문에 주의하자.
*/

#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;

void dec_to_kbase(string& result, int dec, int k) {
    if (k == 0) result = to_string(dec);

    while (dec) {
        result += to_string(dec % k);
        dec /= k;
    }
    reverse(result.begin(), result.end());
}

bool is_prime(ull n) {
    if (n <= 1) return false;

    for(ull i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    if (!n) return 0;
    int answer = 0;
    string nBase;
    dec_to_kbase(nBase, n, k);
    vector<ull> target;
    string p;
    
    for(char x : nBase) {
        if (x == '0') {
            if (p != "") {
                target.push_back(stoull(p));
                p = "";
            }   
        }
        else p += x;
    }
    if (p != "") target.push_back(stoull(p));
    for (ull x : target) {
        if (is_prime(x)) answer++;
    }
    return answer;
}