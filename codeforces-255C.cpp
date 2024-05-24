//https://codeforces.com/problemset/problem/255/C
//C. Almost Arithmetical Progression

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <int> nums(n);
	map <int, set <int> > num_index;
	map <int, int> distinct_num;
	int count_distinct = 0;

	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;

		nums[i] = x;
		if(distinct_num.find(x) == distinct_num.end())
			distinct_num[x] = count_distinct++;
		num_index[x].insert(i);
	}

	vector <vector <int> > dp(n, vector <int>(count_distinct, 0));

	for(int i = 0; i < n; ++i){
		bool is_first_element = true;

		for(int j = i - 1; j >= 0; --j){
			if(nums[j] == nums[i]){
				is_first_element = false;
				int idx = distinct_num[nums[i]];
				dp[i][idx] = dp[j][idx] + 1;
				break;
			}

			int idx = distinct_num[nums[j]];
			
			if(num_index[nums[i]].find(i) == num_index[nums[i]].begin()){
				dp[i][idx] = 2;
				continue;
			}

			int max_pre_len = 0;
			for(auto num_idx : num_index[nums[i]]){
				if(num_idx == i)
					break;
				max_pre_len = max(max_pre_len, dp[num_idx][idx]);
			}

			if(max_pre_len == 0)
				dp[i][idx] = 3;
			else
				dp[i][idx] = max_pre_len + 2;
		}

		if(is_first_element){
			int idx = distinct_num[nums[i]];
			dp[i][idx] = 1;
		}
	}

	int max_len = 0;
	for(auto a : dp)
		for(auto b : a)
			max_len = max(max_len, b);
	cout << max_len << endl;
	return 0;
}
