/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/2217
*/

/*
 * 풀이
 * AAA는 100A + 10A + A로 정리할 수 있다.
 * 입력받은 단어를 위와같이 바꾸고, 각 알파벳에 대해 정리한다.
 * ABC + BCA라고 하면 (100A + 10B + C) + (100B + 10C + A)로 나타낼 수 있고, 각 알파벳에 대해 묶으면
 * 101A + 110B + 11C이다. 계수가 높은 순서대로 9, 8, 7....의 숫자를 부여하면 된다.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> words;

void input() {
    cin >> n;
    words.resize(n);
    for(auto& x : words) cin >> x;
}

void sol() {
    int use_alpha[26] = {0, };
    int result = 0;
    int pow;

    for(auto word : words) {
        pow = 1;
        reverse(word.begin(), word.end());
        for(auto ch : word) {
            use_alpha[ch - 'A'] += pow;
            pow *= 10;
        }
    }

    sort(use_alpha, use_alpha + 26, greater<>());
    for(int i = 0; i < 10; i++) {
        result += use_alpha[i] * (9 - i);
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}