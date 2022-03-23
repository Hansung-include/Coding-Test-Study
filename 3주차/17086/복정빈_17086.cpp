#include <iostream>
#include <queue>

using namespace std;

struct shark {
	int x, y;
};

int n, m, sol;
int map[50][50];
queue < shark> q;
//x와 y값을 가진 shark를 담을 수 있는 큐

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//움직일 수 있는 x값과 y값

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		//bfs탐색 위해 큐의 맨 앞에 있는 값을 x와 y에 저장하고 pop


		for (int k = 0; k < 8; k++) //8개의 방향 이동 가능
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			//이동한 칸의 새로운 x와 y

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (!map[nx][ny])
			{
				q.push({ nx, ny });
				map[nx][ny] = map[x][y] + 1;
				//큐에 x, y값 push한 다음 이동 횟수 추가
			}

		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j])
				q.push({ i, j });
			//맵을 다 구성한 다음 상어가 있는 위치만 큐에 push
		}
	}
	bfs();
	//큐에 있는것은 다 pop하고 map은 각 칸에 안전거리를 가짐
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (sol < map[i][j])
			{
				sol = map[i][j];
			}//가장 먼 거리를 찾음

		}
	}
	cout << sol - 1 << endl;
	//상어가 있는 칸의 안전거리를 1로 설정해둬서 다른 칸의 안전거리 모두 1씩 다 더해져있음
	return 0;
}