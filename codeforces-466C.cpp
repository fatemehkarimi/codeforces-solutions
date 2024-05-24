//https://codeforces.com/problemset/problem/466/C
//Number of Ways

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	vector <int> num(n);

	long long int sum = 0;

	for(int i = 0; i < n; ++i){
		cin >> num[i];
		sum += num[i];
	}

	if(sum % 3 != 0){
		cout << '0' << endl;
		return 0;
	}

	vector <long long int> helper(n, 0);
	long long int sum1 = 0;

	for(int i = n - 2; i >= 0; --i){
		sum1 += num[i + 1];

		if(sum1 == sum / 3)
			helper[i] = helper[i + 1] + 1;
		else
			helper[i] = helper[i + 1];
	}

	long long int count = 0;
	sum1 = 0;
	for(int i = 0; i < n - 2; ++i){
		sum1 += num[i];

		if(sum1 == sum / 3){
			count += helper[i + 1];
		}
	}

	cout << count << endl;

	return 0;
}
