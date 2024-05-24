//https://codeforces.com/problemset/problem/1157/C1
//C1. Increasing Subsequence (easy version)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <int> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	int top = -1;
	int idx_left = 0;
	int idx_right = n - 1;
	int max_length = 0;
	string result;

	while(idx_left <= idx_right && (top < nums[idx_left] || top < nums[idx_right])){
		bool use_left = true;
		if(top < nums[idx_left] && top < nums[idx_right] && nums[idx_right] < nums[idx_left])
			use_left = false;
		if(nums[idx_left] < top)
			use_left = false;
		if(use_left){
			top = nums[idx_left];
			++idx_left;
			++max_length;
			result = result + 'L';
		}
		else{
			top = nums[idx_right];
			--idx_right;
			++max_length;
			result = result + 'R';
		}
	}
	cout << max_length << endl;
	cout << result << endl;
	return 0;
}
