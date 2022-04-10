#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int cost[n][N] = {
      0,
  };
  int dp[n][N] = {
      0,
  };

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> cost[i][j];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
  }

  int result = min({dp[n][0], dp[n][1], dp[n][2]});

  cout << result << '\n';

  return 0;
}
