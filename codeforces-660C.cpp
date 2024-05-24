//https://codeforces.com/problemset/problem/660/C
//C. Hard Process

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k, initial_k;
	cin >> n >> k;
	initial_k = k;

	vector <bool> nums(n);
	for(int i = 0; i < n; ++i){
		int val;
		cin >> val;
		nums[i] = val;
	}

	int pt1 = 0, pt2 = 0;
	vector <int> longest_sub(n, 0);

	if(nums[0])
		longest_sub[0] = 1;
	else if(!nums[0] && k > 0){
		longest_sub[0] = 1;
		--k;
	}

	for(pt2 = 1; pt2 < n; ++pt2)
		if(nums[pt2])
			longest_sub[pt2] = longest_sub[pt2 - 1] + 1;
		else if(!nums[pt2] && k > 0){
			longest_sub[pt2] = longest_sub[pt2 - 1] + 1;
			--k;
		}
		else{
			while(pt1 < pt2)
				if(nums[pt1] || longest_sub[pt1] == 0)
					++pt1;
				else{
					++pt1;
					longest_sub[pt2] = pt2 - pt1 + 1;
					break;
				}
		}

	int index = 0;
	int max_len = 0;
	for(int i = 0; i < n; ++i)
		if(longest_sub[index] < longest_sub[i])
			index = i;

	max_len = longest_sub[index];
	while(index >= 0 && initial_k > 0){
		if(!nums[index]){
			nums[index] = 1;
			--initial_k;
		}
		--index;
	}

	cout << max_len << endl;
	for(auto a : nums)
		cout << a << ' ';
	cout << endl;
	return 0;
}
