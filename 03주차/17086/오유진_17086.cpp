#include <iostream>
#include <queue>

using namespace std;

int map[50][50];
int visited[50][50];
int dx[8]={-1,-1,-1,0,0,1,1,1};    
int dy[8]={0,-1,1,-1,1,0,-1,1};

//아기상어가 있는 자리부터 bfs를 실행하여 인접 칸부터 안전거리를 구한다. 

int main(){
    int N,M;
    queue <pair<int,int>> q; 

    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                q.push(make_pair(i,j));  //아기상어가 있는 곳의 위치를 큐에 먼저 넣음
            }
        }
    }

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M)  
                continue;
            if(map[nx][ny]==0){   //방문하지 않았고, 상어가 없는 칸
                map[nx][ny]=map[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    
    int max=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]>max){   //최댓값 찾음
                max=map[i][j];
            }
        }
    }

    cout<<max-1;

    return 0;

}