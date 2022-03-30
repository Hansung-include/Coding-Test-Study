/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/10814
*/
#include <bits/stdc++.h>
using namespace std;

/*
 * 풀이
 * 블루레이의 최소 크기 = 입력받은 강의 길이중 최댓값, 블루레이의 최대 크기 = 모든 강의 시간의 합
 * 최소 크기와 최대 크기 사이에서 이진 탐색을 진행한다.
*/

vector<int> v;

int blue_ray_count(int amount){
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < v.size() - 1; i++){
        sum += v[i];
        if(sum + v[i + 1] > amount){
            sum = 0;
            ++cnt;
        }
    }
    return ++cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    int start = -1;
    int end = 0;
    int mid, result, temp;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        end += temp;
        start = max(temp, start);
    }

    while(start <= end){
       mid = (start + end) >> 1;
       
        if(blue_ray_count(mid) <= m) {
            end = mid - 1;
            result = mid;
        }
        else {
            start = mid + 1;
        }
    }
    cout << result;
}