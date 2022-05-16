#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int num[500000]; 
int avg(int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i];
	}
	sum=sum / n;
	sum > 0 ? sum += 0.5 : sum -= 0.5;
	return (int)sum;
}
int count(int n) {
	int result;
	int count = 0;
	int cnt[8001] = { 0 };
	for (int i = 0; i < n; i++) {
		cnt[num[i] + 4000]++;//절대값이 4000을 넘지 않기 때문에 -4000~-1은 0~4000으로  0~4000은 4000~8000으로 배열 번호를 새로 바꾼다
	}
	int max_mode = *max_element(cnt, cnt + 8001);//빈도수의 최대값
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] == max_mode) {
			count++;
			result = i - 4000;
		}
		if (count == 2) {//최빈값이 같짖만 두번째로 작은 값일 때
			break;
		}
	}
	return result;
}//최빈값

int main() {
	int N;
	
	cin >>N;
	for (int i = 0; i < N; i++) 
		cin >> num[i];
		
	sort(num, num + N);
	int a = avg(N);
	int b = num[(N-1)/2];
	int c = count(N);
	int d = num[N - 1] - num[0];
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
}
