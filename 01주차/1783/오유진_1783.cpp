#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,M;

  cin>>N>>M;

  if(N==1){   //세로가 1칸일 때 
    cout<<1<<endl;  //이동불가 
  } else if(N==2){  //세로 2칸일 때
    cout<<min(4,(M+1)/2)<<endl;   //2,3만 사용 가능하므로 최대 4칸, 
  } else if(M<7){                 //세로 3칸 이상, 가로 7칸 미만 , 7칸 이상이면 모든 방법 가능
    cout<<min(4,M)<<endl;         //1,4 이용해서 최대 M칸 가능,but 이동제약으로 최대 4칸 가능
  } else{                              
    cout<<M-7+5;                  //7칸까지 모든방법 사용가능 및 총 5칸 방문, 그 이후로 최대 M-7칸 가능
  }

  return 0;
}