#include <iostream>
using namespace std;

const int N = 1e3 + 1;
int dp[N] = {0,};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	string result = "";
	// result = (n%2 == 0) ? "CY" : "SK";

	// »ó±Ù ±âÁØ È¦¼ö=win, Â¦¼ö=lose 
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	
	for(int i=3; i<=n; i++) {
		dp[i] = min(dp[i-1], dp[i-3]) + 1;
	}	
	
	if(dp[n] % 2) { result = "SK"; }
	else { result = "CY"; }
	
	cout << result << '\n'; 
	
	return 0;
}

