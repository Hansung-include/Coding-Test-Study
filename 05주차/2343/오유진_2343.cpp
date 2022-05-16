#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
블루레이 크기를 정해 앞에서부터 차례로 블루레이 크기를 넘지않을때까지 강의 시간을 더하고
블루레이 크기를 넘으면 새로운 블루레이로 카운트해서 다시 크기를 넘지않을 때까지 강의시간을 더함.
모든 강의시간을 다 더한 후에 카운트한 블루레이 개수가 M초과이면 크기를 늘리고,
M이하면 그 크기를 저장한 후 크기를 줄이는 식으로 이진 탐색함. 
long long설정은 10만개 모두가 10만분인 최악의 상황을 가정. 
*/
int main(){
    int N,M;
    long long x;
    int totalTime=0;
    vector<int>blueray;
    long long start=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>x;
        blueray.push_back(x);
        totalTime+=x;
        start=max(start,x);   //블루레이 안에 최소한 한 강의는 들어가야 하므로 start를 최대 강의시간 값으로 설정 
    }
    long long end=totalTime;   //최악은 블루레이 하나에 다 들어가야하므로 총강의시간을 end로 설정
    long long size;

    while(start<=end){
        long long mid=(start+end)/2;
        long long sum=0;
        int count=1;
        for(int i=0;i<N;i++){
            if(sum+blueray[i]>mid){    //강의시간을 더했을 때 블루레이 크기를 넘으면
                count++;               //새로운 블루레이 생성
                sum=0;
            }
            sum+=blueray[i];
        }
        if(count<=M){    //구한 블루레이 개수가 M이하인 경우
            size=mid;    //크기 저정
            end=mid-1;    //기준 크기를 줄임
        }else{            //구한 블루레이 개수가 M초과
            start=mid+1;   // 기준 크기를 늘림 
        }

    } 

    cout<<size<<"\n";

    return 0;
}