/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/1446
*/

/*
 * 풀이
 * 이 문제는 그래프 입력의 전처리와 이후 최단경로를 구하는 방식 모두 생각해야하는 문제이다.
 * 지름길이라고 입력받은 것이 실제로 지름길이 아닐수도 있고, 지름길의 도착지점이 D보다 큰 경우는 따지면 안된다. 이 문제는 이러한 입력데이터가 들어오기 때문에
 * 입력받기전 검사를 하는 단계가 먼저 수행되어야 한다.
 * 
 * 각 노드간의 거리는 자연수기 때문에, 0번정점부터 D번정점까지 방문하면서, 지름길이 있으면 도착지점의 최단경로를 갱신한다.
 * 순차적으로 탐색을 해보면서 최단경로를 구해주면 된다.
*/

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using pii = pair<int, int>;

int N, D;
vector<vector<pii>> graph;

void input() {
    int start, end, len;
    cin >> N >> D;

    graph.resize(D + 1);
    
    for(int i = 0; i < N; i++) {
        cin >> start >> end >> len;
        
        if (len >= end - start) continue;
        if (end > D) continue;

        graph[start].push_back({len, end});
    }
}

void sol() {
    int dist_arr[D + 1];
    fill(dist_arr, dist_arr + D + 1, INF);
   
    dist_arr[0] = 0;
    for(int i = 0; i <= D; i++) {
        if(i) dist_arr[i] = min(dist_arr[i], dist_arr[i - 1] + 1);

        for(auto& elem : graph[i]) {
            dist_arr[elem.second] = min(dist_arr[elem.second], dist_arr[i] + elem.first);
        }
    }

    cout << dist_arr[D];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    sol();    
}