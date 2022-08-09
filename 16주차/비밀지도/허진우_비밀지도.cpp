/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/[1차]비밀지도
*/

/*
 * 풀이
 * 사용 알고리즘 : 비트마스킹
 * 나뉘어진 두개의 지도를 합치기만 하면 되는 문제이다. 문제에서도 나와있지만, 두 지도에서 같은 칸에 하나라도 벽이 있다면, 벽이 있다는 뜻이다.
 * 즉, 그냥 bitwise OR연산을 진행하면 된다. 각 배열의 요소를 모두 OR연산을 진행한 후에, 이를 2진수로 바꾸고, 0과 1을 각각 공백과 #으로 바꿔주면 된다.
 * 진수 변환은 STL중에서 bitset이라는 라이브러리가 있어 사용했다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++) {
        int dec = arr1[i] | arr2[i];
        bitset<16> bin = dec;
        string bin_str;
        for(int j = n - 1; j >= 0; j--) {
            if (bin[j]) bin_str += "#";
            else bin_str += " ";
        }
        answer.push_back(bin_str);
    }
    return answer;
}