#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n=0;
	int cost[3];//색상별 비용
	int home[10000][3];
	
	cin >> n;

	home[0][0]=0;
	home[0][1] = 0;
	home[0][2] = 0;
	//home[1]이 i-1과 비교하기위해 필요.

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];

		//이전집을 나와 다른 색으로 바꾸기 위한 최소값+내가 색을 바꾸는데 들어가는 비용
		//=>이전집 비용+내집 비용
		home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[0];
		home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[1];
		home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[2];
	}

	int result = min(home[n][0], min(home[n][1], home[n][2]));
	//원하는 색으로 바꾸기 위해 필요한 비용이 각각 계산되어있음->세 가지 색 중 비교해보고 가장 작은 수 선택.
	cout << result;

}