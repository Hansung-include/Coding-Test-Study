#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool compare( pair<int,int> &p1, pair<int,int> &p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}

int main(){
    int N,x;
    double sum=0;
    vector <int> v;
    vector<pair<int,int>>mode;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
        sum+=x;
    }

    sort(v.begin(),v.end());

    cout<<(int)floor((sum/N)+0.5)<<endl;  //산술평균
    //cout<<round(sum/N)<<endl;
    //cout<<round(sum/(double)N)

    cout<<v[N/2]<<endl;  //중앙값


    //값과 빈도 수를 함께 묶어 저장해준다. 같은 값을 찾을 때마다 해당 값 빈도 수를 올려준다.
    //빈도수가 큰 순서대로 다시 정렬 후 두번째 수 출력 
    for(int i=0;i<v.size();i++){
        if(mode.empty()){
            mode.push_back(pair<int,int>(v[i],1));
            continue;
        }
        
        if(mode.back().first == v[i]){
            pair<int,int>k=mode.back();
            k.second++;
            mode.pop_back();
            mode.push_back(k);
        }else{
            mode.push_back(pair<int,int>(v[i],1));
        }
    }

    sort(mode.begin(),mode.end(),compare);

    if(mode[0].second==mode[1].second){
        cout<<mode[1].first<<endl;
    }else{
        cout<<mode[0].first<<endl;
    }

    cout<<v.back()-v.front()<<endl;  //범위


    return 0;
}