#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*큐를 이용한 위상정렬, 선행 문제가 있는경우(여기서는 나보다 먼저 세워야할 건물) degree를 1씩 증가시킨다.
degree 가 0인 노드부터 큐에 넣고 time을 (앞 서 세워야 할 건물들 짓는 시간+ 해당 건물 짓는 시간) result에 넣는다.
시간을 넣는 것은 dp 유형.
degree가 0이라는 것은 제일 첫번째 세워져야될 건물이거나, 먼저 세워야 할 건물들이 다 세워졌다는 뜻이다. 
*/

int N;
int degree[501];
int Time[501];
int result[501];
vector <int> building[501];

void topologySort(){
    queue <int> q;
    for(int i=1;i<=N;i++){
        if(degree[i]==0){
            q.push(i);
            result[i]=Time[i];
        }
    }

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<building[x].size();i++){
            int next=building[x][i];
            degree[next]--;

            result[next]=max(result[next],result[x]+Time[next]);
            if(degree[next]==0){
                q.push(next);
            }
        }
    }

    for(int i=1;i<=N;i++){
        cout<<result[i]<<"\n";
    }
        
}

int main(){
    int cost;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>Time[i];
        while(1){
            int a;
            cin>>a;
            if(a==-1) break;
            building[a].push_back(i);
            degree[i]++;
        }
        
    }

    topologySort();


    return 0;
}