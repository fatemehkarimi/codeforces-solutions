//https://codeforces.com/problemset/problem/1197/C
//C. Array Splitting

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

	vector <int> diffs;
	for(int i = 0; i < n - 1; ++i)
		diffs.push_back(nums[i] - nums[i + 1]);
	sort(diffs.begin(), diffs.end());

	long long int result = nums[n - 1] - nums[0];
	for(int i = 0; i < k - 1; ++i)
		result += diffs[i];
	cout << result << endl;
	return 0;
}
