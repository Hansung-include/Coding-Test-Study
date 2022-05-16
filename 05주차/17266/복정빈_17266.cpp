#include <iostream>

using namespace std;

int n, m, lamp[100001];


int bs()
{
	int l = 0;
	int r = 100000;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		//가로등을 두기 좋은 위치
		int flag = 0;


		if (lamp[0] > mid)
			flag = 1;
		//이미 놓여진 위치에서 굴다리를 다 비추는 경우 flag=0

		for (int i = 0; i < m - 1; i++)
		{
			//
			if (lamp[i + 1] - lamp[i] > mid * 2)
			{
				flag = 1;
				break;
			}
		}

			if (n - lamp[m - 1] > mid)
				flag = 1;

			//유효한경우 불가능하게 높이 감소
			if (!flag)
				r = mid - 1;
			//불가능할 경우 높이 증가
			else l = mid + 1;
	}
		return l;

}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> lamp[i];
	cout << bs();
}