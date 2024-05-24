//https://codeforces.com/problemset/problem/1006/C
//C. Three Parts of the Array

#include <iostream>
#include <vector>
#define lld long long int

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	vector <lld> nums(n);

	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	int ptr1 = 0, ptr2 = n - 1;

	lld sum_found = 0;
	lld curr_sum_left = 0, curr_sum_right = 0;

	while(ptr1 <= ptr2){
		if(curr_sum_left < curr_sum_right){
			curr_sum_left += nums[ptr1];
			++ptr1;
		}
		else{
			curr_sum_right += nums[ptr2];
			--ptr2;
		}
		if(curr_sum_left == curr_sum_right)
			sum_found = curr_sum_left;
	}

	cout << sum_found << endl;
	return 0;
}
