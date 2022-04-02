/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/17266
*/

/*
 * 풀이
 * 최소 높이 1, 최대 높이는 다리의 길이로 정하고 이진탐색을 진행한다.
*/

#include <bits/stdc++.h>
using namespace std;

int bridge_len;
int lamp_cnt;
int st, ed;
int* lamp_position;

void input(){
    cin >> bridge_len >> lamp_cnt;
    lamp_position = new int[lamp_cnt];
    st = 1;
    ed = bridge_len;
    for(int i = 0; i < lamp_cnt; i++) {
        cin >> lamp_position[i];
        ed = max(lamp_position[i] , ed);
    }
}

bool shine_all(int height) {
    for (int i = 0; i < lamp_cnt; i++) {
        if (i == 0) {
            if (lamp_position[i] - height > 0) return false;
        }

        if (lamp_position[i] - height > (i ? lamp_position[i - 1] + height : 0)) return false;
        
        if (i == lamp_cnt - 1) {
            if (lamp_position[i] + height < bridge_len) return false;
        }
    }
    return true;
}

void solution() {
    int mid;
    int result = 0;

    while (st <= ed) {
        mid = (st + ed) / 2;
        
        if (shine_all(mid)) {
            ed = mid - 1;
            result = mid;
        }
        else {
            st = mid + 1;
        }
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solution();
    delete[] lamp_position;
}