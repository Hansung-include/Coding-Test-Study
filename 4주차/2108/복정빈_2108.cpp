#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>



using namespace std;

int res = 0;
int result = 0;
bool second = false;
int maxn = -4000;
int minn = 4000;
int n;
int nums[500001];
int sum;



int center(int n, int nums[])
{
	sort(nums, nums + n);
	//크기순으로 정렬
	return nums[n/2];
}


int many(int n, int nums[])
{

	for (int i = 0; i < n; i++)
	{
		if (res <= count(nums, nums + n, nums[i]))
		{
			res = count(nums, nums + n, nums[i]);
		}	

	}
	//제일 높은 빈도수 찾기

	sort(nums, nums + n);
	//오름차순으로 재정렬

	for (int i = 0; i < n; i+=res)
	{
		if (count(nums, nums+n, nums[i])==res)
		{
			result = nums[i];
			
			if (second)
				break;
			second = true;
		}
		
	}
	return result;
	//제일 높은 빈도수인 res와 값이 같은 수를 찾아서 첫번째는 패스하고 두번째수를 저장 후 리턴
}


int range(int n, int nums[])
{
	for (int i = 0; i < n; i++)
	{
		if (maxn <= nums[i])
			maxn = nums[i];
		//최댓값 구하기

		if (minn >= nums[i])
			minn = nums[i];
		//최솟값 구하기
	}
	return maxn - minn;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//속도

	cin >> n;
	sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];

		sum += nums[i];
	}
	//수를 입력받으면서 합구하기

	int q1 = round(double(sum) / n);
	//산술평균을 구한 후 반올림

	//cout << q1 << "\n"; //산술평균
	//cout << center(n, nums) << "\n"; //중앙값
	//cout << many(n, nums) << "\n"; //최빈값
	//cout << range(n, nums) << "\n";

	printf("%d \n", q1);
	printf("%d \n", center(n, nums));
	printf("%d \n", many(n, nums));
	printf("%d \n", range(n, nums));

}