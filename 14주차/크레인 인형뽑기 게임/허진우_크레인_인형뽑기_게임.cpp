/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 프로그래머스/크레인 인형뽑기 게임
 */

/*
 * 풀이
 * 사용 알고리즘 : 스택
 * 크레인을 통해 맨 위의 인형만을 가져가고(pop), 바구니에 넣고(push), 바구니의 맨 위(top) 인형과 가져온 인형을 비교하기 때문에, 스택이 생각났다.
 * 그래서 입력받은 board를 스택으로 이루어진 벡터로 재구성하고, 인형뽑기 기계의 top과 바구니의 top을 비교해가면서 push, pop여부를 결정한다.
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int target;
    vector<stack<int>> bd(board.size());
    stack<int> busket;
    
    // board 전처리
    for(int i = board.size() - 1; i >= 0; i--)  {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j]) bd[j].push(board[i][j]);
        }
    }

    // 풀이
    for(int i : moves) {
        i--;
        if(!bd[i].empty()) {
            target = bd[i].top();
            bd[i].pop();
            
            if(!busket.empty() && target == busket.top()) {
                answer+=2;
                busket.pop();
            }
            else busket.push(target);
        }
    }
    return answer;
}