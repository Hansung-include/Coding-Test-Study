#include <iostream>
using namespace std;
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int main()
{
	int tall[9];
	int temp;
	int sumTall=0;
	int over = 0;

	//9�� �Է¹���
	for (int i = 0; i < 9;i++)
	{
		cin >> tall[i]; //Ű 9�� �Է¹���
		sumTall += tall[i];//��� Ű�� ���� ��
	}

	for (int i = 8; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			if (tall[j] > tall[j + 1])
				SWAP(tall[j], tall[j + 1], temp);
	}
	//������û��


	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{

			if (over == 0)
			{
				if (sumTall - tall[i] - tall[j] == 100)
				{
					for (int k = 0; k < 9; k++)
					{
						if (i == k || j == k)
							continue;
						cout << tall[k] << endl;
					}
					
					over = 1;//���� �������� ��� �Ѱ��� ����ϱ� ���ؼ�
					break;

				}
			}
		}
	}

}