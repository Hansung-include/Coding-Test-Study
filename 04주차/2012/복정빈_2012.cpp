#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; int e; 
long long total;
vector<int> v;

int main()
{
	cin >> n; //�л� n��

	for (int i = 0; i < n; i++)
	{
		cin >> e;
		v.push_back(e);
		//�л����� �������� �Է¹޾Ƽ� ���Ϳ� �Է�
	}

	sort(v.begin(), v.end());
	//�л����� �������� ������������ ����

	for (int i = 0; i < n; i++)
	{
		total += abs(v[i] - (i + 1));
			//total=������-�������(1���� n�����)
	}

	cout << total;

}