
#include <iostream>

using namespace std;

int result[16]={0,};

int main(){
    int N,T[16],P[16];
    int sum=0;

    cin>>N;
  
    for(int i=1;i<=N;i++){
        cin>>T[i]>>P[i];
    }

    for(int i=N;i>0;i--){
        if(i+T[i]<=N+1){  //당일 포함 상담하므로 N+1
            result[i]=max(result[i+1],P[i]+result[i+T[i]]); //현재 time 바로 뒤의 최대수익과 현재 time을 기준으로 한 최대수익 비교  
            sum=max(result[i],sum); //최대 수익인지 비교 
        }else{
            result[i]=result[i+1];
        }
    }

    cout<<sum;


    return 0;
}

/*
실수한 코드
1  2  3  4  5  6  7  8  9  10
5  4  3  2  1  1  2  3  4  5
50 40 30 20 10 10 20 30 40 50  
                     


#include <iostream>

using namespace std;

int result[16]={0,};

int main(){
    int N,T[16],P[16];
    int sum=0;

    cin>>N;
  
    for(int i=1;i<=N;i++){
        cin>>T[i]>>P[i];
    }

    for(int i=N;i>0;i--){
        if(i+T[i]<=N+1){
            result[i]=P[i]+result[i+T[i]]);
            sum=max(result[i],sum);
        }
    }

    cout<<sum;


    return 0;
}*/