#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;
int arr[N];
int dp[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	int result;
	result = dp[0] = arr[0];
	
	for(int i=1; i<n; i++) {
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}
	
	cout << result << '\n';
	
	return 0;
}

