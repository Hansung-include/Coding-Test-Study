#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 예산들 중 최댓값을 구하는 것이므로 원소 순서 상관없음.
sort로 정렬 한 후 상한액과 배열 원소 중 더 작은 값을 더해 그 합이 총 예산을 넘지 않는 식으로 이진 탐색 진행
*/

int main(){
    int N,M,x,result;
    vector<int> budget;  //벡터 사용
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        budget.push_back(x);
    }
    cin>>M;

    sort(budget.begin(),budget.end());   //정렬

    int start=0;
    int end=budget.back();
    while(start<=end){
        int sum=0;
        int mid=(start+end)/2;     
        for(int i=0;i<budget.size();i++){
            sum+=min(budget[i],mid);   //상한액과 지방별 예산 값을 비교해 작은 값을 더함
        }
        if(sum>M){    //합이 총 예산 초과
            end=mid-1;   //상한액을 더 줄여줌 
        }else{      //합이 총 예산 이하
            start=mid+1;    //상한액을 더 늘려줌
            result=mid;     //해당 상한액 저장
        }
    }

    cout<<result<<"\n";
}

/*  배열 사용
int main(){
    int N,M;
    int sum,result;
    int budget[10000];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>budget[i];
    }
    cin>>M;

    sort(budget,budget+N);
    
    int start=0;
    int end=budget[N-1];

    while(start<=end){
        sum=0;
        int mid=(start+end)/2;
        
        for(int i=0;i<N;i++){
            sum+=min(budget[i],mid);
        }
        if(M>=sum){
            result=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }

    cout<<result<<"\n";

    return 0;
}*/