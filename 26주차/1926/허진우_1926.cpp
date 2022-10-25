/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/1926
*/

/*
 * 풀이
 * 시용 알고리즘: 그래프탐색
 * 전형적인 그래프 탐색 문제이다. 그림을 발견하면 개수를 1 증가시키고 탐색을 통해 그림의 넓이를 찾는다.
 * 그래프에 0만 들어오는, 그러니까 그림이 없는 테스트케이스가 존재할 수 있다. 그렇기에 최대 넓이를 저장할 변수를 -1이 아닌 0으로 초기화했다.
 * -1로 초기화하면 그림이 없는 경우, 그림의 넓이가 -1로 출력되기 때문이다.
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
vector<vector<int>> graph;

void input() {
	cin >> n >> m;
	graph.resize(n, vector<int>(m));
	for (auto& row : graph) {
		for (int& x : row) cin >> x;
	}
}

int bfs(int st_x, int st_y) {
	queue<pair<int, int>> q;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int area = 0;
	
	q.push({st_x, st_y});
	graph[st_y][st_x] = -1; // 방문 처리
	area++;

	while(!q.empty()) {
		auto [cur_x, cur_y] = q.front();
		q.pop();

		for(int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
			
			if (graph[next_y][next_x] == 1) {
				graph[next_y][next_x] = -1;
				q.push({next_x, next_y});
				area++;
			}
		}
	}

	return area;
}

void sol() {
	int cnt = 0;
	int max_area = 0;
 
	for(int y = 0; y < n; y++) {
		for(int x = 0; x < m; x++) {
			if (graph[y][x] == 1) {
				cnt++;
				max_area = max(max_area, bfs(x, y));
			}
		}
	}
	
	cout << cnt << endl << max_area;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	sol();
}