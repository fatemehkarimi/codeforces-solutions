//https://codeforces.com/problemset/problem/285/C
//C. Building Permutation

#include <iostream>
#include <vector>
#include <algorithm>
#define lld long long int
using namespace std;

int main(void)
{
	lld n = 0;
	cin >> n;
	vector <lld> nums(n);
	for(lld i = 0; i < n; ++i)
		cin >> nums[i];

	sort(nums.begin(), nums.end());
	lld minNumMoves = 0;
	for(lld i = 0; i < n; ++i)
		minNumMoves += abs(i + 1 - nums[i]);

	cout << minNumMoves << endl;
	return 0;
}
