//C. Less or Equal
//https://codeforces.com/problemset/problem/977/C

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector <int> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	if(k > n){
		cout << -1 << endl;
		return 0;
	}

	if(k == n){
		cout << nums[n - 1] << endl;
		return 0;
	}

	if(k == 0 && nums[0] > 1){
		cout << 1 << endl;
		return 0;
	}
	else if(k == 0 && nums[0] == 1){
		cout << -1 << endl;
		return 0;
	}

	if(nums[k - 1] != nums[k])
		cout << nums[k - 1] << endl;
	else
		cout << "-1" << endl;
	return 0;
}
