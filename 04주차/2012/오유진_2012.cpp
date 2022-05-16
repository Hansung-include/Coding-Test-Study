#include <iostream>
#include<algorithm>

using namespace std;

//생각한 등수를 오름차순으로 정렬해서 불만도의 합을 구한다.
//그리디 알고리즘-오름차순으로 정렬해서 현재의 최적의 방법을 구함
//합을 int가 아닌 long long으로 하는 것이 핵심(최악의 경우 int를 넘어가기 때문)  

int main(){
    int N;
    long long sum=0;
    int student[500000];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>student[i];
    }

    sort(student,student+N);

    for(int i=0;i<N;i++){
        sum+=abs(student[i]-(i+1));
    }

    cout<<sum<<endl;

    return 0;
}