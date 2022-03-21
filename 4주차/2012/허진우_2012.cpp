#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    /*
    * 풀이
    * 예상 등수와 최대한 비슷하게 실제 등수를 부여하는 문제.
    * 그리디적으로 생각해서, 예상 등수가 작을수록 더 높은 등수를 부여해주면 된다.
    * 2 1 3 1 1 이라는 예제가 있다고 생각해보면 그냥 1 1 1 2 3의 순서대로 등수를 부여해주면 불만도는 7
    * 여기서 (예상)2등과 (예상)5등이 자기가 받은 등수대로 받으면 되는거 아닌가? 싶기도 하지만, 결국 차이는 없다.
    * 
    * -> 결론: 입력받은 후, 정렬을 수행하고 불만도를 계산해준다.
    */

    int tc;
    long long ans = 0;
    vector<int> v;
    
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < tc; i++) {
        ans += abs(v[i] - i - 1);
    }

    cout << ans;
}