#include <iostream>
#include <queue>

using namespace std;

int n, k;
int trace[100000];
queue<int> q;//큐 생성

int bfs()
{
	q.push(n);//수빈의 위치 큐에 입력
	trace[n] = 0; //이동횟수
	while (!q.empty())
	{
		int p = q.front(); //p가 큐에서 제일 앞에 있는 값으로 계속 업데이트.
		q.pop();
		//큐에서 제일 앞에 있는 값 업데이트 후 pop.
		if (p == k)
			return trace[p];
		//p=수빈의 위치랑 동생의 위치가 동일해지면 입력된 횟수 return.

		if (p - 1 >= 0 && trace[p - 1] == 0/*중복 막으려고*/)
		{
			q.push(p - 1);
			trace[p - 1] = trace[p] + 1;
		}
		if (p + 1 <= 100000 && trace[p + 1] == 0)
		{
			q.push(p + 1);
			trace[p + 1] = trace[p] + 1;
		}
		if (p * 2 <= 100000 && trace[2 * p] == 0)
		{
			q.push(p * 2);
			trace[p * 2] = trace[p] + 1;
		}

		//큐에 수빈의 위치 p값을 계속 변경시켜서 새로 업데이트 함. trace[업데이트 된 새로운 p값]에 업데이트 횟수만큼 더해줌.->카운팅 해줌.
		//계속해서 업데이트 된 수빈의 위치 p값이 결국 동생의 위치 k값과 동일해지면 카운팅된 trace[p]값을 return함.
	}
}


int main()
{
	cin >> n >> k;
	cout << bfs();
	return 0;
}