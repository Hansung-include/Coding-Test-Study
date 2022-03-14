#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int sum=0,n=0;
	int a = 0, b = 0;
	int h[9];
	int real[7];
	
	for (int i = 0; i < 9; i++) {
		cin >> h[i];
		sum += h[i];
	}
	n = sum - 100;//난쟁이가 아닌 두명의 키의 합을 구하기 위해

	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {
			if (h[i] + h[j] == n) {
				h[i] = -1; h[j] = -1;//난쟁이의 키는 자연수이므로 -1로 저장하여 난쟁이가 아님을 표시한다.
				break;
			}
		}
	}

	sort(h, h + 9);
	for(int i=2;i<9;i++)//앞에서 두번째까지는 난쟁이가 아니기때문에 세번째 배열부터 출력한다.
		cout << h[i];
}
