#include <iostream>
#include <algorithm>

using namespace std;

//모든 경우를 다 계산해주면 됨.
//nP7 보다는 100-nP2 -> 총 합에서 2개를 빼서 100을 만듬.
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int h[9];
  int sum=0;
  for(int i=0;i<9;i++){
    cin>>h[i];
    sum+=h[i];  // 총 합에서 2개를 빼주기 위해. 
  }
  
  sort(h,h+9);   //오름차순 정렬

  for(int i=0;i<9;i++){     //순차적으로 2가지씩 고름
    for(int j=i+1;j<9;j++){  
      if(sum-(h[i]+h[j])==100){   //총 합에서 2개를 뺀 값
        for(int k=0;k<9;k++){
          if(k==i||k==j) continue;   //2개를 제외
          cout<<h[k]<<endl;
        }
          return 0;
      }
    }
  }

  return 0;
}