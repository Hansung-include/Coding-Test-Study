#include <iostream>
#include <queue>


using namespace std;

struct wolf
{
	int x, y;
};


char map[500][500];
int r, c;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };



int main()
{
	cin >> r >> c;

	queue <wolf> q;//늑대의 위치를 담을 큐

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			//맵 작성

			if (map[i][j] == 'W')
			{
				q.push({ i, j });
			}//늑대의 위치를 큐에 담음
		}
	}

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			//늑대가 이동할 수 있는 칸(상하좌우)

			if (nx >= 0 && nx < r && ny >= 0 && ny < c)
			{
				if (map[nx][ny] == '.')
				{
					map[nx][ny] = 'D';
				}//늑대 주변에 비어있을 경우 울타리로 늑대를 못움직이게함
				else if (map[nx][ny] == 'S')
				{
					cout << 0 << endl;
					return 0;
				}//늑대 주변에 양이 있을경우 방법이 없는것으로 판단하고 종료
			}

		}

	}

	cout << 1 << endl;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}

}