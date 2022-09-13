/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/피로도
*/

/*
 * 풀이
 * 사용 알고리즘 : 완전 탐색, 순열
 * 사실 처음 봤을 때에는 그리디나 DP로 접근해야할 것 같았는데, 개수가 생각보다 많지 않아서, 완전탐색으로 진행해도 무방할 것 같았다.
 * 모든 경우를 따지기 위해, C++의 next_permutation함수를 통해 순열을 구성했고, 이를 통해 모든 경우를 탐색했다.
*/

#include <bits/stdc++.h>
#define ALL(X) X.begin(),X.end()
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int curr_fat;
    int cnt;
    sort(ALL(dungeons));
        
    do {
        cnt = 0;
        curr_fat = k;
        for(auto& elem : dungeons) {
            if (curr_fat < elem[0]) break;
            
            curr_fat -= elem[1];
            cnt++;
        }
        answer = max(cnt, answer);
	} while(next_permutation(ALL(dungeons)));
    
    return answer;
}