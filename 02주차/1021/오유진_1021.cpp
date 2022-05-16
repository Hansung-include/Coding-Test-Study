#include <iostream>
#include <deque>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,x,num,index;
    int count=0;
    deque <int> dq;

    cin>>N>>M;
    for(int i=1;i<=N;i++){
        dq.push_back(i);    //덱 크기만큼 숫자를 넣어줌
    }

    while(M--){       //뽑아야 하는 숫자의 개수 
        cin>>num;

        for(int i=0;i<dq.size();i++){
            if(dq[i]==num){   //뽑아야 하는 숫자의 인덱스 찾기
                index=i;
                break;
            }
        }

        if(index<dq.size()-index){  // 왼쪽으로 이동할지 오른쪽으로 할지, 왼쪽 이동   
            while(1){
                if(dq.front()==num){     
                    dq.pop_front();      
                    break;
                }
                count++;               //이동횟수
                dq.push_back(dq.front());    //앞의 숫자를 뒤로 옮겨줌
                dq.pop_front();
            }
        }else{          //오른쪽 이동
            while(1){
                if(dq.front()==num){
                    dq.pop_front();   
                    break;
                }
                count++;        //이동횟수 
                dq.push_front(dq.back());  //뒤의 숫자를 앞으로 옮겨줌
                dq.pop_back();         
            }
        }
    }

    cout<<count<<endl;

    return 0;
    

}