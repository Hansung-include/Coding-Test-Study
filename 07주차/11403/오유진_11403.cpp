#include <iostream>
#include <vector>

using namespace std;

// 플로이드 워셜 방법

int main(){
    int n;
    int G[100][100];

    cin>>n; //정점의 개수

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>G[i][j];    //인접행렬
        }    
    }

// k를 거쳐서 i부터 j까지 갈 수 있는지 확인
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){   //출발
            for(int j=0;j<n;j++){   //도착
                if(G[i][k] && G[k][j]){
                    G[i][j]=1;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}