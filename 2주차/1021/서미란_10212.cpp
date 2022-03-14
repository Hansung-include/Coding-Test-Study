#include <iostream>
#include <deque>
using namespace std;

int main() {
	int count = 0;
	deque<int> dq;
	int N, M; int num[50];
	cin >> N >> M;
	for(int i = 1; i<=N;i++)
		dq.push_back(i);
	for (int i = 0; i < M; ++i) {
		int idx;
		cin>>idx;
		int loc = 1;
		for (deque<int>::iterator iter = dq.begin(); iter < dq.end(); iter++) {
			if (*iter == idx) 
				break;	
			loc++;//뽑아내려는 수의 위치
		}
		int right = dq.size() - loc+1;
		int left = loc - 1;
		if (left >right||left==right) {
			for (int i = 1; i <=right; i++) {
				int end = dq.back();
				dq.pop_back();
				dq.push_front(end);			
			
			}
			count += right;
		}		
		if (left < right) {
			for (int i = 0; i < left; i++) {
				int front = dq.front();
				dq.pop_front();
				dq.push_back(front);
				
			}
			count += left;

		}
		
		dq.pop_front();
	}
	cout << count << endl;
}


