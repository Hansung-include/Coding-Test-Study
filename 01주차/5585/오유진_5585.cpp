#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num;
  int cnt=0;
  int change[6]={500,100,50,10,5,1}; //잔돈

  cin>>num;
  num=1000-num; 

  for(int i=0;i<6;i++){
    if(num>=change[i]){  //가능한만큼 큰 잔돈 순으로 나누어줌
      cnt+=num/change[i]; //잔돈 개수를 더함
      num%=change[i];
    }
  }

  cout<< cnt;

  return 0;
}