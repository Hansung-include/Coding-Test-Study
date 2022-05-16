#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; int e; 
long long total;
vector<int> v;

int main()
{
	cin >> n; //학생 n명

	for (int i = 0; i < n; i++)
	{
		cin >> e;
		v.push_back(e);
		//학생들의 예상등수를 입력받아서 벡터에 입력
	}

	sort(v.begin(), v.end());
	//학생들의 예상등수를 오름차순으로 정렬

	for (int i = 0; i < n; i++)
	{
		total += abs(v[i] - (i + 1));
			//total=예상등수-실제등수(1부터 n등까지)
	}

	cout << total;

}