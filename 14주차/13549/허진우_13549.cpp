/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/13549
*/

/*
 * 풀이
 * 사용 알고리즘 : 다익스트라, 0-1 bfs
 * 숨바꼭질1(1697)의 경우는 간선의 가중치가 모두 같기 때문에, 단순한 bfs로 풀 수 있었다.
 * 하지만 이번 문제는 2*x로 이동할 때 가중치가 0이고, x + 1, x - 1의 위치로 이동하는 경우 가중치가 1로, 가중치가 다른 모습을 볼 수 있다.
 * 이 경우 제일 짧은 시간을 구해야 하기 때문에, 다익스트라로 최단거리를 구하면 된다.
 * 
 * 다익스트라로 푸는 경우는 일반적인 풀이이지만, 풀이 이후 조금 더 공부해보니, 이런 경우에 최적화된 알고리즘이 존재했다. 0-1 bfs이다. 
 * 일반적인 bfs와 달리, 이 bfs알고리즘은 간선의 가중치가 다르지만, 그 가중치가 모두 0, 1인 경우에 사용할 수 있다.
 * 보편적인 다익스트라 알고리즘은 O(ElogV) 또는 O(ElogE)의 시간복잡도가 발생하지만, 이 0-1 bfs알고리즘은 O(V+E)의 선형 시간복잡도가 발생하여 더 효율적으로 구할 수 있다.
 * bfs와 달리, 이 0-1 bfs는 덱을 사용하고, 가중치가 0인 경우 front에 push하고, 1인 경우 back에 push한다. 나머지는 bfs와 동일하다.
*/

#include <bits/stdc++.h>
#define INF (int)1e9
#define LEN ((int)1e5 + 5)
using namespace std;
using pii = pair<int, int>;

void sol(int n, int k) { // 다익스트라
	int dist_arr[2 * LEN];
	fill(dist_arr, dist_arr + 2 * LEN, INF);
	bool visit[2 * LEN] = { false };
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	pq.push({ 0, n });
	dist_arr[n] = 0;
	
	while(!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		if (visit[cur.second]) continue;
		visit[cur.second] = true;

		if (cur.second <= k && dist_arr[cur.second * 2] > cur.first) {
			dist_arr[cur.second * 2] = cur.first;
			pq.push({dist_arr[cur.second * 2], cur.second * 2});
		}
		if (cur.second <= 2 * k && dist_arr[cur.second + 1] > cur.first + 1) {
			dist_arr[cur.second + 1] = cur.first + 1;
			pq.push({dist_arr[cur.second + 1], cur.second + 1});
		}
		if (cur.second > 0 && dist_arr[cur.second - 1] > cur.first + 1) {
			dist_arr[cur.second - 1] = cur.first + 1;
			pq.push({dist_arr[cur.second - 1], cur.second - 1});
		}
	}
	cout << dist_arr[k] << endl;
}

void sol2(int n, int k) { // 0-1 BFS
	deque<int> dq;
	int dist_arr[2 * LEN];
	fill(dist_arr, dist_arr + 2 * LEN, INF);
	bool visit[2 * LEN] = { false };
	
	dq.push_front(n);
	dist_arr[n] = 0;

	while(!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		if (visit[cur]) continue;
		visit[cur] = true;

		if (cur <= k && dist_arr[cur * 2] > dist_arr[cur]) {
			dist_arr[cur * 2] = dist_arr[cur];
			dq.push_front(cur * 2);
		}
		if (cur <= 2 * k && dist_arr[cur + 1] > dist_arr[cur] + 1) {
			dist_arr[cur + 1] = dist_arr[cur] + 1;
			dq.push_back(cur + 1);
		}
		if (cur > 0 && dist_arr[cur - 1] > dist_arr[cur] + 1) {
			dist_arr[cur - 1] = dist_arr[cur] + 1;
			dq.push_back(cur - 1);
		}
	}
	cout << dist_arr[k];
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	sol(n, k);
	// sol2(n, k);
}