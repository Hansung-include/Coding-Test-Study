#include <iostream>

using namespace std;

int main()
{
	int n=0;
	cin >> n;

	//완벽하게 게임을 한다고 가정=>일단 다 3개씩 가져가고 그 이후는 1개씩 가져감.
	//ex)3, 6. 9, 12.
	//즉, 홀수일때 상근이가 이기고 짝수일때 창영이가 이김.

	if (n % 2 == 0)
	{
		cout << "CY";
	}
	else
		cout << "SK";



}