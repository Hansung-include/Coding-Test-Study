//10814
//벡터의 stable_sort를 이용하여 정렬
//나중에 입력된 번호와 먼저 입력된 번호를 비교하여 출력 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first; //큰 번호를 먼저 출력

}
int main() {
	int N;
	
	cin>> N;
	vector<pair<int, string>> v(N);
	for (int i = 0; i < N; i++) 
		cin >> v[i].first >> v[i].second;
	
	stable_sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < N; i++) 
		cout << v[i].first << " "<<v[i].second<< "\n";
	
}
