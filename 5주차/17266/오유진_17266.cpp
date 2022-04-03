#include <iostream>

using namespace std;

/*
가로등 높이를 이진 탐색함.
첫번째 가로등이 길 0까지 비출 수 있는지 확인,
가로등 사이들을 모두 비출 수 있는지 확인
마지막 가로등이 길 N까지 비출 수 있는지 확인 
*/


int main(){
    int N,M;
    int lamp[100001];
    int h;

    cin>>N;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>lamp[i];
    }
    int start=0;
    int end=100000;

    while(start<=end){
        int mid=(start+end)/2;
        bool flag=true;
        if(lamp[0]>mid){   //첫번재 가로등이 0까지 비출 수 있는지
            flag=false;
        }

        for(int i=0;i<M-1;i++){   
            if(lamp[i+1]-lamp[i]>mid*2){  //가로등 사이를 비출 수 있는지 
                flag=false;
                break;
            }
        }

        if(N-lamp[M-1]>mid){   //마지막 가로등이 N까지 비출 수 있는지
            flag=false;
        }

        if(flag){    //모든 길을 비출 수 있다면
            h=mid;   //가로등 높이 저장
            end=mid-1;    //가로등을 더 낮게
        }else{
            start=mid+1;   //가로등을 더 높게
        }

    }
    cout<<h<<"\n";

    return 0;
}