/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/신고 결과 받기
 */

/*
 * 풀이
 * 사용 알고리즘 : 문자열 파싱, 순차 탐색
 * 한 유저가 같은 유저를 여러번 신고했다는 뜻은 같은 문자열이 report에 여러개 들어있다는 뜻이다. 즉 중복을 제거하면 이 문제가 해결된다.
 * 신고 형식은 "유저id 신고한 id" 로 들어오기 때문에 공백을 통해 문자열을 파싱한다.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>  

#define all(x) (x).begin(), (x).end()
using namespace std;

inline int get_index(vector<string>& id_list, string& name) {
    for(int i = 0; i < id_list.size(); i++)
        if (id_list[i] == name) return i;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0); // 답
    vector<int> report_cnt(id_list.size(), 0); // 각 유저가 신고당한 횟수
    pair<string, string> user_report; // <유저id, 유저가 신고한 id>
    
    // report 중복 제거, 동일 유저가 한 유저를 여러번 신고했다면, 같은 형식의 데이터가 여러개 들어있을 수 밖에 없다.
    sort(all(report));
    report.erase(unique(all(report)), report.end());
    
    // 신고당한 횟수 작성
    for(auto rp : report) {
        stringstream ss(rp);
        getline(ss, user_report.first, ' ');
        getline(ss, user_report.second, ' ');
        
        report_cnt[get_index(id_list, user_report.second)]++;
    }
    
    // 답안 작성
    for(auto rp : report) {
        stringstream ss(rp);
        getline(ss, user_report.first, ' ');
        getline(ss, user_report.second, ' ');
        
        if (report_cnt[get_index(id_list, user_report.second)] >= k)
            answer[get_index(id_list, user_report.first)]++;
    }
    
    return answer;
}