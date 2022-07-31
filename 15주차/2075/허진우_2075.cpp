/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/2075
*/

/*
 * 풀이
 * 사용 알고리즘 : 우선순위 큐
 * 처음에는 1500 * 1500 * 4Byte = 9백만Byte이고, 이를 MB단위로 변환하면 9MB정도 나오기 때문에 메모리제한에 걸리지 않을 것 같아서, 그냥 단순하게 모든 숫자를 저장했다.
 * 하지만 메모리 초과가 발생했다. 기본적으로 C++17로 제출하면, 2020KB, 그러니까 2MB정도 먹고 들어가는데, 이것과 내부적으로 사용하는 여러 변수들 때문에 메모리초과가 발생한 것 같다.
 * 
 * 이걸 조금 알아봤었는데, iostream 헤더에서는 각각 istream객체인 cin과 ostream객체인 cout, cerr를 만들어두는데, 이것들이 900KB정도 잡아먹는다고 한다.
 * 나머지는 확정한건 아니지만 libc를 초기화할때 사용한 용량이라고 한다. 확실하지는 않다.
 * 
 * 여튼, 전체를 저장하는 문제가 아니라는 것은 알았고, 정렬을 사용하자니, std::sort의 시간복잡도는 O(nlogn)이고, 이를 n^2번 반복하기 때문에 시간초과가 날 것이다.
 * 그래서 우선순위 큐를 구성하고, 이를 통해 문제를 풀었다.
*/

#include <bits/stdc++.h>
using namespace std;

void sol(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int temp;
    for(int i = 0; i < n * n; i++) {
        cin >> temp;
        pq.push(temp);
        if(pq.size() > n) pq.pop();
    }
    cout << pq.top();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    sol(n);
}