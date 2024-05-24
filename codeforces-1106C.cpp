//https://codeforces.com/problemset/problem/1106/C

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector <int> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	long long int minSum = 0;
	int i = 0, j = n - 1;

	while (i < j){
		minSum += ((nums[i] + nums[j]) * (nums[i] + nums[j]));
		++i;
		--j;
	}

	cout << minSum << endl;
	return 0;
}
