//https://codeforces.com/problemset/problem/1093/C
//Mishka and the Last Exam

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	vector <long long int> nums(n / 2);

	for(int i = 0; i < n / 2; ++i)
		cin >> nums[i];

	vector <long long int> result(n);

	result[0] = 0;
	result[n - 1] = nums[0];

	for(int i = 1; i < n / 2; ++i)
		if(nums[i] == nums[i - 1]){
			result[i] = result[i - 1];
			result[n - i - 1] = result[n - i];
		}
		else if(nums[i] < nums[i - 1]){
			result[i] = result[i - 1];
			result[n - i - 1] = nums[i] - result[i - 1];
		}
		else{
			result[i] = nums[i] - result[n - i];
			result[n - i - 1] = result[n - i];
		}

	for(auto a : result)
		cout << a << ' ';
	cout << endl;

	return 0;
}
