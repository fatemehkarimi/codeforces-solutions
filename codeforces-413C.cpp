//https://codeforces.com/problemset/problem/413/C
//C. Jeopardy!

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector <long long int> nums(n);

	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	vector <long long int> auction;
	for(int i = 0; i < m; ++i){
		int idx;
		cin >> idx;
		--idx;
		auction.push_back(nums[idx]);
		nums[idx] = -1;
	}

	long long int total_sum = 0;
	for(auto a : nums)
		if(a != -1)
			total_sum += a;

	for(auto & a : auction)
		if(a < total_sum)
			a = total_sum;

	while(true){
		auto max_idx = std::max_element(auction.begin(), auction.end());

		if(*max_idx == -1)
			break;

		total_sum += *max_idx;
		*max_idx = -1;

		for(auto &a : auction)
			if(a != -1 && a < total_sum)
				a = total_sum;

	}

	cout << total_sum << endl;
	return 0;
}
