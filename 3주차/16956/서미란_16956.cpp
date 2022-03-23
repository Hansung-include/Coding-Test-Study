#include <iostream>

using namespace std;
char farm[501][501];
int visited[501][501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int ny, nx, R, C;
//울타리의 최소 개수를 묻는 문제가 아니다
//늑대가 있는 칸을 중심으로 상하좌우 검사하여 양이 없는 칸에 울타리 설치
int main() {
	bool a = true;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> farm[i][j];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (farm[i][j] == 'W') {//늑대일 경우만  검사

				for (int b = 0; b < 4; b++) {//상하좌우 검사
					nx = i + dx[b];
					ny = j + dy[b];
					if (-1 < nx && nx < R && -1 < ny && ny < C) {
						if (farm[nx][ny] == '.')
							farm[nx][ny] = 'D';

						else if (farm[nx][ny] == 'S')//늑대 옆에 양이 이씨는지 검사
							a = false;
					}
				}
			}


		}


	}
	cout << (int)a << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cout << farm[i][j];
		cout << endl;
	}

	return 0;
}
