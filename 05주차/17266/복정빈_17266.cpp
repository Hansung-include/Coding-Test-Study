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
		//���ε��� �α� ���� ��ġ
		int flag = 0;


		if (lamp[0] > mid)
			flag = 1;
		//�̹� ������ ��ġ���� ���ٸ��� �� ���ߴ� ��� flag=0

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

			//��ȿ�Ѱ�� �Ұ����ϰ� ���� ����
			if (!flag)
				r = mid - 1;
			//�Ұ����� ��� ���� ����
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