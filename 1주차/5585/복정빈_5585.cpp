

#include <iostream>
using namespace std;
int cal(int b, int c);

int main()
{
    int a;
    cin >> a; //지불할 금액
    int b = 1000 - a;//거스름돈

    int fin = cal(b, 500);
    b = b - (500 * cal(b, 500)); //500원을 다 준 다음 남은 잔돈

    fin += cal(b, 100);
    b = b - (100 * cal(b, 100));

    fin += cal(b, 50);
    b = b - (50 * cal(b, 50));

    fin += cal(b, 10);
    b = b - (10 * cal(b, 10));

    fin += cal(b, 5);
    b = b - (5 * cal(b, 5));

    fin += cal(b, 1);


    cout << fin << endl;

}

int cal(int b, int c)
{
    int result = 0;
    while (b / c >= 1) //1이상 나눠지는지 
    {
        result++;//갯수 추가
        b -= c;//남은 잔돈
    }
    return result; //잔돈의 수
}




