//http://codeforces.com/problemset/problem/706/B
//B. Interesting drink

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bSearch(vector <int> & nums, int left, int right, int key);

int main(void)
{
	int n = 0;
	cin >> n;

	vector <int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	int d;
	cin >> d;
	for (int i = 0; i < d; ++i){
		int money;
		cin >> money;

		cout << bSearch(nums, -1, n, money) << endl;

	}

	return 0;
}

int bSearch(vector <int> & nums, int left, int right, int key)
{
	while (right - left > 1){
		int middle = left + (right - left) / 2;

		if (nums[middle] > key)
			right = middle;
		else
			left = middle;

	}
	return right;
}
