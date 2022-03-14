#include <iostream>
#include <algorithm>
using namespace std;
int T[15], P[15]; int sum[15];
int pay= 0;

int main() {
	int N; int a=0;
	int price = 0;
	
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = N - 1; i >= 0; i--) {//뒤에서부터 연산 시작
		if (i + T[i] > N)//상담 완료일이 퇴사하는 날보다 길면 일을 하지 못하므로 0으로 저장
			sum[i] = 0;
		else {
			sum[i] = P[i] + sum[i + T[i]];
			pay = max(sum[i], pay);//이전값과 현재값을 비교하여 더 큰값을 저장
		}
		//cout << endl;
		//cout << i << " " << sum[i] << endl;
	}
	//cout << endl;
	cout << pay;

} 
