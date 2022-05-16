#include <iostream>

using namespace std;

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
char map[500][500];

//늑대가 있는 곳의 상하좌우에 모두 울타리를 친다.
int main() {
    int R,C;
    int flag=1;
    
    cin>>R>>C;
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]=='W'){       //늑대가 있는 자리 확인
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];

                    if(nx>=R||ny>=C||nx<0||ny<0){
                        continue;
                    }

                    if(map[nx][ny]=='S')   //늑대 바로 옆에 양이 있음
                        flag=0;

                    if(map[nx][ny]=='.')
                        map[nx][ny]='D';
                }
            }
        }
    }
    
    if(flag==0){
        cout<<0<<endl;
    }else{
        cout<<1<<endl;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<map[i][j];
            }
        cout<<endl;
        }
    }
    
    return 0;
}