#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}//오름차순으로 할지 내림차순으로 할지 내가 설정

int main()
{
	int n;
	cin >> n;
	vector<pair<int, string>> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	stable_sort(arr.begin(), arr.end(), compare);
	//arr의 벡터의 처음부터 끝까지 정렬
	//arr벡터의 안에 있는 tmp의 first를 우선 오름차순하는데 이때 동일한 값이 있을경우 second의 값을 오름차순한다.

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}



}