//https://codeforces.com/problemset/problem/1131/C
//Birthday

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector <int> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	list <int> result;

	result.push_back(nums.back());
	bool left = 1;
	for(int i = nums.size() - 2; i >= 0; --i){
		if(left)
			result.push_front(nums[i]);
		else
			result.push_back(nums[i]);

		left = !left;
	}

	for(auto a : result)
		cout << a << ' ';
	cout << endl;

	return 0;
}
