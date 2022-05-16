#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//직접 자료형을 만들어 나이,이름뿐만 아니라 가입 순서를 위해 인덱스도 저장해준다.


typedef struct id{
    int index;
    int age;
    string name;
}id;

bool compare(const id &p1, const id &p2){
    if(p1.age==p2.age){   //나이가 같을 시 
        return p1.index<p2.index;   //인덱스 오름차순,즉 가입한 순서대로 
    }
    return p1.age<p2.age;
}

int main(){
    int N;
    vector <id> v;
    cin>>N;
    for(int i=0;i<N;i++){
        id p;
        cin>>p.age>>p.name;
        p.index=i;
        v.push_back(p);
    }

    sort(v.begin(),v.end(),compare); 

    for(int i=0;i<N;i++){
        cout<<v[i].age<<" "<<v[i].name<<"\n";
    }

    return 0;
}



/*
bool compare(pair<int,string> a,pair<int,string> b){
    return a.first <b.first;
}

int main(){
    int N,num;
    string name;
    vector <pair<int,string>> v;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num>>name;
        v.push_back(make_pair(num,name));
    }

    stable_sort(v.begin(),v.end(),compare);
    //sort(v.begin(),b.end(),compare);
    
    for(int i=0;i<N;i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    //"\n"말고 endl 사용 시 시간초과!

    return 0;
}*/