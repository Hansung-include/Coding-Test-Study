#include <iostream>

using namespace std;
/*
연속된 색깔이 아니면 된다. 
i번째 집을 각각 해당 색으로 칠했을 경우(총 3가지,3개의 배열)와 i-1번째 집을 그 색이 아닌 나머지 두색으로 칠했을 경우를 
비교한 후  더해서 더 작은 값을 저장해준다.
이렇게 되면 house[i][0]에는 i번을 0에 해당되는 색깔로 칠했을 때의 최솟값이 들어가게 된다.  
*/

int main(){
    int N;
    int house[1001][3];
    int cost[3];

    house[0][0]=0;   //house[i][0]= 빨강
    house[0][1]=0;   //house[i][1]=초록
    house[0][2]=0;   //house[i][2]=파랑

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>cost[0]>>cost[1]>>cost[2];
        house[i][0]=min(house[i-1][1],house[i-1][2])+cost[0];
        house[i][1]=min(house[i-1][0],house[i-1][2])+cost[1];
        house[i][2]=min(house[i-1][0],house[i-1][1])+cost[2];
    }

    cout<<min(house[N][0],min(house[N][1],house[N][2]))<<"\n";

    return 0;
}