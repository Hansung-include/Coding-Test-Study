/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/1543
*/

/*
 * 풀이
 * 사용 알고리즘 : 브루트포스
 * 문서의 맨 처음부터 시작했을때의 최대, 그리고 그 다음글자에서부터 시작했을때의 최대의 값.... 을 계속 구해보면서
 * 어느때가 제일 최댓값을 가지는지 세면 된다.
*/

#include <bits/stdc++.h>
using namespace std;

string doc, word;

bool equal(int start) {
	for (int i = 0; i < word.size(); i++)
		if (doc[start + i] != word[i]) return false;
	return true;
} 

void sol() {
	int answer = -1;
	int cnt;
	for (int i = 0; i < doc.length(); i++) {
		cnt = 0;
		for (int j = i; j < doc.length();) {
			if (equal(j)) {
				cnt++;
				j += word.size();
			}
			else j++;
		}
		answer = max(answer, cnt);
	}
	cout << answer;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	getline(cin, doc);
	getline(cin, word);
	sol();
}