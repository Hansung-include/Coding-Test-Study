#include <iostream>
#include <vector>

using namespace std;

/*
dp[i]에는 i번째까지 수 중에 연속된 합이 가장 큰 경우가 들어간다.
현재 값을 더한 경우가 더 클 수도 있고 현재 값이 더 클 수도 있기 때문에
구하는 방법은 dp[i-1]에 현재 i번째 수를 더한 값과 i번째 수만을 비교해서
더 큰 값을 dp[i]에 넣는다.
ex(dp[4]==-5, array[5]==10 일 때 dp[4]+array[5]보다 array[5]가 더 큼)
현재까지 연속된 수의 합 중에 가장 큰 결과를 result에 넣는다. 이것을 계속해서 result와 dp[i]를 비교해준다.
ex) 9 1 -7 4 13 일때
   dp={9,10,3,4,17}
   result = 9-> 10 max(10,9) -> 10 (10,3) -> 10 (10,4) ->17 (10,17)
   마지막에 최종적으로 dp[0]과 비교해준다.(for문에서 dp[0]과 비교를 못해주었으므로)   
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int array[100001];
    int dp[100001];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    int result=-1000;
    dp[0]=array[0];
    for(int i=1;i<N;i++){
        dp[i]=max(dp[i-1]+array[i],array[i]);
        result=max(result,dp[i]);
    }
    result=max(result,dp[0]);

    cout<<result;

    return 0;
     
}