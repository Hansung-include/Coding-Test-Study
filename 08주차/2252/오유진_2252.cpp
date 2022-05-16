#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*큐를 이용한 위상정렬, 선행 문제가 있는경우(여기서는 나보다 앞 선 사람) degree를 1씩 증가시킨다.
degree 가 0인 노드부터 큐에 넣어 순서를 세운다. 
*/

int N;
vector <int> person[32001];
int degree[32001];

void topologySort(){
    queue <int> q;
    vector <int> result;
    for(int i=1;i<=N;i++){
        if(degree[i]==0){
            q.push(i);
            result.push_back(i);
        }
    }

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<person[x].size();i++){
            int next=person[x][i];
            if(--degree[next]==0){
                q.push(next);
                result.push_back(next);
            }
        }
    }

    for(int i=0;i<N;i++){
        cout<<result[i];
    }
}


int main(){
    int M,A,B;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>A>>B;
        person[A].push_back(B);
        degree[B]++;
    }

    topologySort();

    return 0;
}