//https://codeforces.com/problemset/problem/467/C
//George and Job

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;

	vector <int> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	vector <long long int> intervals;

	int i = 0;
	long long int sum = 0;
	for(; i < m; ++i)
		sum += nums[i];

	intervals.push_back(sum);
	for(; i < n; ++i){
		sum -= nums[i - m];
		sum += nums[i];
		intervals.push_back(sum);
	}

	int nn = intervals.size();
	vector < vector <long long int> > arr(k, vector <long long int>(nn, INT_MIN));

	for(int i = 0; i < nn; ++i){
		arr[0][i] = intervals[i];
		if(i - 1 >= 0)
			arr[0][i] = max(arr[0][i], arr[0][i - 1]);
	}

	for(int j = 1; j < k; ++j)
		for(int i = 0; i < nn; ++i){
			if(i - m >= 0 && arr[j - 1][i - m] != INT_MIN)
				arr[j][i] = max(arr[j][i], arr[j - 1][i - m] + intervals[i]);
			if(i - 1 >= 0)
				arr[j][i] = max(arr[j][i], arr[j][i - 1]);
		}

	cout << arr[k - 1][nn - 1] << endl;

	return 0;
}
