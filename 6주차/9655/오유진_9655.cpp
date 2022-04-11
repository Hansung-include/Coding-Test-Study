#include <iostream>

using namespace std;

/* 한 개 또는 세개를 가져가는 것이므로 
홀수개가 남으면 상근, 짝수개가 남으면 창영이가 이긴다.
(직접 몇가지 경우를 계산해도 규칙이 보임)
*/

int main(){
    int N;
    cin>>N;
    if(N%2==1){
        cout<<"SK";
    }else{
        cout<<"CY";
    }
}