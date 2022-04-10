#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int ori[100000];
	int dp[100000];
	int ans = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> ori[i];
	}
	dp[0] = ori[0];
	ans = dp[0];
	//ori는 입력받은 숫자 그대로를 저장. dp는 연속되는 수들 큰 값을 저장.

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + ori[i], ori[i]);
		//이전까지의 연속된 수와 자기자신을 더한 수와 자기 자신 중 큰 값 사용.
		//-> 연속을 계속 이어갈지, 끊을지 결정
		ans = max(ans, dp[i]);
		//이전의 답과 새로운 값과의 비교
	}

	cout << ans;



}