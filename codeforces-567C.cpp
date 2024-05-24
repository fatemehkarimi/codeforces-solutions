//https://codeforces.com/problemset/problem/567/C
//Geometric Progression

#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector <int> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	vector <long long int> count(n, 1);

	for(int j = 2; j <= 3; ++j){
		map <int, long long int> pre;
		int pre_count = count[0];
		count[0] = 0;
		for(int i = 1; i < n; ++i){
			pre[nums[i - 1]] += pre_count;
			pre_count = count[i];

			if(nums[i] % k == 0){
				count[i] = pre[nums[i] / k];
			}
			else
				count[i] = 0;
		}
	}

	long long int result = 0;
	for(auto a : count)
		result += a;

	cout << result << endl;

	return 0;
}
